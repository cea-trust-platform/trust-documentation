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

#include <Option_CGNS.h>
#include <Motcle.h>
#include <Param.h>

Implemente_instanciable(Option_CGNS, "Option_CGNS", Interprete);
// XD Option_CGNS interprete Option_CGNS 1 Class for CGNS options.

bool Option_CGNS::SINGLE_PRECISION = false; /* NOT BY DEFAULT */
bool Option_CGNS::MULTIPLE_FILES = false; /* NOT BY DEFAULT */
bool Option_CGNS::PARALLEL_OVER_ZONE = false; /* NOT BY DEFAULT */
bool Option_CGNS::USE_LINKS = false; /* NOT BY DEFAULT */

Sortie& Option_CGNS::printOn(Sortie& os) const { return Interprete::printOn(os); }
Entree& Option_CGNS::readOn(Entree& is) { return Interprete::readOn(is); }

Entree& Option_CGNS::interpreter(Entree& is)
{
  Param param(que_suis_je());
  param.ajouter_non_std("SINGLE_PRECISION", (this)); // XD_ADD_P rien If used, data will be written with a single_precision format inside the CGNS file (it concerns both mesh coordinates and field values).
  param.ajouter_non_std("MULTIPLE_FILES", (this)); // XD_ADD_P rien If used, data will be written in separate files (ie: one file per processor).
  param.ajouter_non_std("PARALLEL_OVER_ZONE", (this)); // XD_ADD_P rien If used, data will be written in separate zones (ie: one zone per processor). This is not so performant but easier to read later ...
  param.ajouter_non_std("USE_LINKS", (this)); // XD_ADD_P rien If used, data will be written in separate files; one file for mesh, and then one file for solution time. Links will be used.
  param.lire_avec_accolades_depuis(is);

  if ((MULTIPLE_FILES || PARALLEL_OVER_ZONE) && USE_LINKS)
    {
      Cerr << "Error in Option_CGNS :" << finl;
      Cerr << "       - You can not activate both options 'MULTIPLE_FILES'/or/'PARALLEL_OVER_ZONE' & 'USE_LINKS' !!!" << finl;
      Cerr << "       - If you want linked CGNS files, remove the options 'MULTIPLE_FILES'/or/'PARALLEL_OVER_ZONE'..." << finl;
      Process::exit();
    }

  return is;
}

int Option_CGNS::lire_motcle_non_standard(const Motcle& mot_cle, Entree& is)
{
  int retval = 1;

  if (mot_cle == "SINGLE_PRECISION")
    {
      Cerr << mot_cle << " => CGNS data will be written in a single precision format ..." << finl;
      SINGLE_PRECISION = true;
    }
  else if (mot_cle == "MULTIPLE_FILES")
    {
      Cerr << mot_cle << " => CGNS data will be written in a multiple files ..." << finl;
      MULTIPLE_FILES = true;
      Cerr << mot_cle << " => CGNS data will be written in separate zones ..." << finl;
      PARALLEL_OVER_ZONE = true;
    }
  else if (mot_cle == "PARALLEL_OVER_ZONE")
    {
      Cerr << mot_cle << " => CGNS data will be written in separate zones ..." << finl;
      PARALLEL_OVER_ZONE = true;
    }
  else if (mot_cle == "USE_LINKS")
    {
      Cerr << mot_cle << " => CGNS data will be written in separate files (mesh, solution ...)" << finl;
      USE_LINKS = true;
    }
  else
    retval = -1;

  return retval;
}
