//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Convection_Diffusion_Chaleur_WC.h>
#include <Convection_Diffusion_Espece_Binaire_WC.h>
#include <Convection_Diffusion_Espece_Multi_WC.h>
#include <Navier_Stokes_WC.h>
void instancie_src_ThHyd_Dilatable_Weakly_Compressible_Equations() {
Cerr << "src_ThHyd_Dilatable_Weakly_Compressible_Equations" << finl;
Convection_Diffusion_Chaleur_WC inst1;verifie_pere(inst1);
Convection_Diffusion_Espece_Binaire_WC inst2;verifie_pere(inst2);
Convection_Diffusion_Espece_Multi_WC inst3;verifie_pere(inst3);
Navier_Stokes_WC inst4;verifie_pere(inst4);
}
