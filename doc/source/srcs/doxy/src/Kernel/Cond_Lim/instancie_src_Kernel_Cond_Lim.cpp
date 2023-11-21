//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Dirichlet_entree_fluide_leaves.h>
#include <Dirichlet_paroi_defilante.h>
#include <Echange_externe_impose.h>
#include <Echange_global_impose.h>
#include <Neumann_paroi.h>
#include <Scalaire_impose_paroi.h>
#include <Symetrie.h>
void instancie_src_Kernel_Cond_Lim() {
Cerr << "src_Kernel_Cond_Lim" << finl;
Entree_fluide_vitesse_imposee inst1;verifie_pere(inst1);
Entree_fluide_vitesse_imposee_libre inst2;verifie_pere(inst2);
Entree_fluide_Fluctu_Temperature_imposee inst3;verifie_pere(inst3);
Entree_fluide_temperature_imposee inst4;verifie_pere(inst4);
Entree_fluide_V2_impose inst5;verifie_pere(inst5);
Entree_fluide_fraction_massique_imposee inst6;verifie_pere(inst6);
Entree_fluide_alpha_impose inst7;verifie_pere(inst7);
Entree_fluide_Flux_Chaleur_Turbulente_imposee inst8;verifie_pere(inst8);
Dirichlet_paroi_defilante inst9;verifie_pere(inst9);
Echange_externe_impose inst10;verifie_pere(inst10);
Echange_global_impose inst11;verifie_pere(inst11);
Neumann_paroi inst12;verifie_pere(inst12);
Scalaire_impose_paroi inst13;verifie_pere(inst13);
Symetrie inst14;verifie_pere(inst14);
}
