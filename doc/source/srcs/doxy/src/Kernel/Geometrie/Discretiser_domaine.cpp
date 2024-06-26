/****************************************************************************
* Copyright (c) 2022, CEA
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

#include <Discretiser_domaine.h>
#include <Domaine_VF_inst.h>

Implemente_instanciable(Discretiser_domaine,"Discretiser_domaine",Interprete_geometrique_base);
// XD discretiser_domaine interprete discretiser_domaine 0 Useful to discretize the domain domain_name (faces will be created) without defining a problem.
// XD  attr domain_name ref_domaine domain_name 0 Name of the domain.

Sortie& Discretiser_domaine::printOn(Sortie& os) const
{
  return Interprete::printOn(os);
}

Entree& Discretiser_domaine::readOn(Entree& is)
{
  return Interprete::readOn(is);
}

Entree& Discretiser_domaine::interpreter_(Entree& is)
{
  associer_domaine(is);
  Domaine& dom=domaine();
  Domaine_VF_inst domaine_dis;
  domaine_dis.associer_domaine(dom);
  domaine_dis.discretiser();
  return is;
}




