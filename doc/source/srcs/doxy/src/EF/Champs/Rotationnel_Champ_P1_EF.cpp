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

#include <Rotationnel_Champ_P1_EF.h>
#include <Champ_P1_EF.h>

Implemente_instanciable(Rotationnel_Champ_P1_EF,"Rotationnel_Champ_P1_EF",Champ_Fonc_P0_EF);

Sortie& Rotationnel_Champ_P1_EF::printOn(Sortie& s) const
{
  return s << que_suis_je() << " " << le_nom();
}

Entree& Rotationnel_Champ_P1_EF::readOn(Entree& s)
{
  return s ;
}

void Rotationnel_Champ_P1_EF::associer_champ(const Champ_P1_EF& un_champ)
{
  mon_champ_= un_champ;
}

void Rotationnel_Champ_P1_EF::mettre_a_jour(double tps)
{
  me_calculer(tps);
  changer_temps(tps);
}

void Rotationnel_Champ_P1_EF::me_calculer(double tps)
{
  Cerr << __FILE__ << (int)__LINE__ << "Rotationnel_Champ_P1_EF::me_calculer : ERROR : the curl of a P1 vector fields in a FE context has not been implemented yet." << finl;
  abort();
}
