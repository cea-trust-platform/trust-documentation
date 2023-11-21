//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Convection_Diffusion_Chaleur_Turbulent_QC.h>
#include <Convection_Diffusion_Concentration_Turbulent.h>
#include <Convection_Diffusion_Espece_Binaire_Turbulent_QC.h>
#include <Convection_Diffusion_Espece_Multi_Turbulent_QC.h>
#include <Convection_Diffusion_Temperature_Turbulent.h>
#include <Navier_Stokes_Turbulent.h>
#include <Navier_Stokes_Turbulent_QC.h>
void instancie_src_ThHyd_Turbulence_Equations() {
Cerr << "src_ThHyd_Turbulence_Equations" << finl;
Convection_Diffusion_Chaleur_Turbulent_QC inst1;verifie_pere(inst1);
Convection_Diffusion_Concentration_Turbulent inst2;verifie_pere(inst2);
Convection_Diffusion_Espece_Binaire_Turbulent_QC inst3;verifie_pere(inst3);
Convection_Diffusion_Espece_Multi_Turbulent_QC inst4;verifie_pere(inst4);
Convection_Diffusion_Temperature_Turbulent inst5;verifie_pere(inst5);
Navier_Stokes_Turbulent inst6;verifie_pere(inst6);
Navier_Stokes_Turbulent_QC inst7;verifie_pere(inst7);
}
