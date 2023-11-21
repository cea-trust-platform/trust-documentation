//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Modele_turbulence_hyd.h>
#include <Modele_turbulence_hyd_null.h>
#include <Modele_turbulence_scal.h>
#include <Modele_turbulence_scal_null.h>
void instancie_src_ThHyd_Turbulence_Modeles() {
Cerr << "src_ThHyd_Turbulence_Modeles" << finl;
Modele_turbulence_hyd inst1;verifie_pere(inst1);
Modele_turbulence_hyd_null inst2;verifie_pere(inst2);
Modele_turbulence_scal inst3;verifie_pere(inst3);
Modele_turbulence_scal_null inst4;verifie_pere(inst4);
}
