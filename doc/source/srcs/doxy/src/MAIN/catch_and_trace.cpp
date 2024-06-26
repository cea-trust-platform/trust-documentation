/****************************************************************************
* Copyright (c) 2024, CEA
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

#include <catch_and_trace.h>

// Wrapper struct for pclose to avoid function pointer in template argument of smart pointer:
// https://stackoverflow.com/questions/76867698/what-does-ignoring-attributes-on-template-argument-mean-in-this-context
struct pipe_deleter
{
  int operator()(FILE *stream) const
  {
    return pclose(stream);
  }
};

int exec_cmd_and_get_output(const char* cmd, std::string& result)
{
  std::array<char, 128> buffer;
  std::unique_ptr<FILE, pipe_deleter> pipe(popen(cmd, "r"), pipe_deleter());
  if (!pipe)
    {
      return 0; // popen failed - unable to execute system command
    }
  while (fgets(buffer.data(), (int)buffer.size(), pipe.get()) != nullptr)
    {
      result += buffer.data();
    }
  return 1;
}

static bool crit_err_hdlr_done = false;
void crit_err_hdlr(True_int sig_num, siginfo_t * info, void * ucontext)
{
  if (crit_err_hdlr_done) return;
  crit_err_hdlr_done = true;
  std::cerr << "Error handler triggered!! See Journal - process ID: " << Process::me() << std::endl;
  Process::Journal() << "signal " << (int)sig_num
                     << " (" << strsignal(sig_num) << "), address is "
                     << long(info->si_addr) << finl; //" from "

  void * array[100];
  int size = backtrace(array, 100);

  Process::Journal() << __FUNCTION__ << " backtrace returned " << size << " frames\n" << finl;

  // Extract symbols from backtrace
  char ** messages = backtrace_symbols(array, size);

  // Skip first stack frame (points here) and print out backtrace
  for (int i = 1; i < size && messages != nullptr; ++i)
    {
      Process::Journal() << "[proc " << Process::me() << "]: (" << i << ") " << messages[i] << finl;
      // Find first occurence of '(' or ' ' in message[i] and assume
      // everything before that is the file name (don't go beyond 0 though, string terminator)
      size_t p = 0;
      while(messages[i][p] != '(' && messages[i][p] != ' '
            && messages[i][p] != 0)
        ++p;

      // Call 'addr2line' system utility to extract line number in the source code:
      char syscom[256];
      snprintf(syscom, 256, "addr2line %p --functions -e %.*s | tr '\n' ' ' | c++filt", array[i], (True_int)p, messages[i]);
      std::string output;
      int ret = exec_cmd_and_get_output(syscom, output);
      if(!ret)
        Process::Journal() << "(Unable to execute 'addr2line' to get line number in source ...)" << finl;
      else
        Process::Journal() << "[proc " << Process::me() << "]: (" << i << ") ----> "
                           << output << finl;
    }
  Process::Journal() << finl;
  free(messages);

  Process::exit();
}

void install_handlers()
{
  struct sigaction sigact;
  sigemptyset(&sigact.sa_mask);
  sigact.sa_sigaction = crit_err_hdlr;
  sigact.sa_flags = SA_RESTART | SA_SIGINFO;

  if (sigaction(SIGABRT, &sigact, (struct sigaction *)nullptr) != 0)
    {
      std::cerr << "FATAL ERROR setting handler for signal " << SIGABRT
                << " (" << strsignal(SIGABRT) << ")" << std::endl;
      Process::exit();
    }

  if (sigaction(SIGFPE, &sigact, (struct sigaction *)nullptr) != 0)
    {
      std::cerr << "FATAL ERROR setting handler for signal " << SIGFPE
                << " (" << strsignal(SIGFPE) << ")" << std::endl;
      Process::exit();
    }
  std::cerr << "Custom error handlers correctly installed. SIGFPE and SIGABRT redirected." << std::endl;
}

