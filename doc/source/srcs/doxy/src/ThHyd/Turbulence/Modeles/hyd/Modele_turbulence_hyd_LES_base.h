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

#ifndef Modele_turbulence_hyd_LES_base_included
#define Modele_turbulence_hyd_LES_base_included

#include <Modele_turbulence_hyd_0_eq_base.h>

/*! @brief Classe Modele_turbulence_hyd_LES_base Classe representant le modele de turbulence sous maille pour les
 *
 *     equations de Navier-Stokes.
 *
 * @sa Modele_turbulence_hyd_0_eq_base
 */
class Modele_turbulence_hyd_LES_base: public Modele_turbulence_hyd_0_eq_base
{
  Declare_base_sans_constructeur(Modele_turbulence_hyd_LES_base);
public:
  Modele_turbulence_hyd_LES_base();
  void set_param(Param& param) override;
  void verifie_loi_paroi_diphasique();
  int preparer_calcul() override;
  void completer() override;
  virtual void calculer_longueurs_caracteristiques()=0;
  void calculer_energie_cinetique_turb() override;

  // sauter la classe mere
  int reprendre(Entree& is) override { return Modele_turbulence_hyd_base::reprendre(is); }
  void imprimer(Sortie& is) const override { return Modele_turbulence_hyd_base::imprimer(is); }

protected:
  DoubleVect l_;
  Motcle methode_;

  static constexpr double CSM1 = 0.063, CSMS1 = 0.112; // Constante viscosite turbulente modele sous maille, sous maille selectif
  static constexpr double CSM2 = 0.37; // Constante energie cinetique turbulente modele sous maille
};

#endif /* Modele_turbulence_hyd_LES_base_included */
