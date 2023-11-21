//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Loi_paroi_log.h>
#include <Transport_turbulent_GGDH.h>
#include <Transport_turbulent_SGDH.h>
#include <Viscosite_turbulente_l_melange.h>
#include <Viscosite_turbulente_multiple.h>
void instancie_src_ThHyd_Multiphase_Turbulence() {
Cerr << "src_ThHyd_Multiphase_Turbulence" << finl;
Loi_paroi_log inst1;verifie_pere(inst1);
Transport_turbulent_GGDH inst2;verifie_pere(inst2);
Transport_turbulent_SGDH inst3;verifie_pere(inst3);
Viscosite_turbulente_l_melange inst4;verifie_pere(inst4);
Viscosite_turbulente_multiple inst5;verifie_pere(inst5);
}
