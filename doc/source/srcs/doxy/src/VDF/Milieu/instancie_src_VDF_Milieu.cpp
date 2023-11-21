//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <EDO_Pression_th_VDF_Gaz_Parfait.h>
#include <EDO_Pression_th_VDF_Gaz_Reel.h>
#include <EOS_Tools_VDF.h>
void instancie_src_VDF_Milieu() {
Cerr << "src_VDF_Milieu" << finl;
EDO_Pression_th_VDF_Gaz_Parfait inst1;verifie_pere(inst1);
EDO_Pression_th_VDF_Gaz_Reel inst2;verifie_pere(inst2);
EOS_Tools_VDF inst3;verifie_pere(inst3);
}
