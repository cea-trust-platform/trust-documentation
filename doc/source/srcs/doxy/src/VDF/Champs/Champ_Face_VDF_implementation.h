/****************************************************************************
* Copyright (c) 2023, CEA
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

#ifndef Champ_Face_VDF_implementation_included
#define Champ_Face_VDF_implementation_included

#include <Champ_implementation_divers.h>

class Frontiere_dis_base;
class Domaine_VDF;
class Sortie;

class Champ_Face_VDF_implementation : public Champ_implementation_divers
{
public:
  DoubleVect& valeur_a_elem(const DoubleVect& position, DoubleVect& val, int le_poly) const override;
  double valeur_a_elem_compo(const DoubleVect& position, int le_poly, int ncomp) const override;
  DoubleTab& valeur_aux_elems(const DoubleTab& positions, const IntVect& les_polys, DoubleTab& valeurs) const override;
  DoubleTab& valeur_aux_elems_passe(const DoubleTab& positions, const IntVect& les_polys, DoubleTab& valeurs) const;
  DoubleVect& valeur_aux_elems_compo(const DoubleTab& positions, const IntVect& les_polys, DoubleVect& valeurs, int ncomp) const override;
  DoubleTab& valeur_aux_sommets(const Domaine&, DoubleTab&) const override;
  DoubleVect& valeur_aux_sommets_compo(const Domaine&, DoubleVect&, int) const override;
  DoubleTab& remplir_coord_noeuds(DoubleTab& positions) const override;
  int remplir_coord_noeuds_et_polys(DoubleTab& positions, IntVect& polys) const override;
  int imprime_Face(Sortie&, int) const;

protected:
  virtual const Domaine_VDF& domaine_vdf() const = 0;
  double interpolation(const double, const double, const double) const;
  DoubleTab& trace(const Frontiere_dis_base& fr, const DoubleTab& y, DoubleTab& x, int distant) const;

private:
  DoubleTab& valeur_aux_elems_(const DoubleTab& val_face, const DoubleTab& positions, const IntVect& les_polys, DoubleTab& valeurs) const;
  DoubleVect& valeur_a_elem_(const DoubleTab& val_face, const DoubleVect& position, DoubleVect& val, int le_poly) const;
};

#endif /* Champ_Face_VDF_implementation_included */
