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

#include <Modif_bord_to_raccord.h>
#include <EFichier.h>

Implemente_instanciable(Modif_bord_to_raccord,"Modif_bord_to_raccord",Interprete_geometrique_base);
// XD modif_bord_to_raccord interprete modif_bord_to_raccord -1 Keyword to convert a boundary of domain_name domain of kind Bord to a boundary of kind Raccord (named boundary_name). It is useful when using meshes with boundaries of kind Bord defined and to run a coupled calculation.
// XD  attr domaine ref_domaine domain 0 Name of domain
// XD  attr nom_bord chaine nom_bord 0 Name of the boundary to transform.

Sortie& Modif_bord_to_raccord::printOn(Sortie& os) const
{
  return Interprete::printOn(os);
}

Entree& Modif_bord_to_raccord::readOn(Entree& is)
{
  return Interprete::readOn(is);
}

Entree& Modif_bord_to_raccord::interpreter_(Entree& is)
{
  Nom nom_bord;
  associer_domaine(is);
  is>>nom_bord;
  Domaine& dom=domaine();

  Bord& bord=dom.bord(nom_bord);

  Raccords& listrac=dom.faces_raccord();

  Raccord racc_base;
  racc_base.typer("Raccord_local_homogene");
  Raccord_base& racc=racc_base.valeur();

  // on caste en Frontiere pour pouvoir faire la copie ...
  ref_cast(Frontiere,racc)=ref_cast(Frontiere,bord);
  listrac.add(racc_base);

  Bords& listbord=dom.faces_bord();
  listbord.suppr(dom.bord(nom_bord));
  dom.fixer_premieres_faces_frontiere();
  return is;
}
