//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Conduction.h>
#include <Echange_couplage_thermique.h>
#include <Echange_interne_global_impose.h>
#include <Echange_interne_global_parfait.h>
#include <Pb_Conduction.h>
#include <Solide.h>
#include <Traitement_particulier_Solide.h>
void instancie_src_ThSol() {
Cerr << "src_ThSol" << finl;
Conduction inst1;verifie_pere(inst1);
Echange_couplage_thermique inst2;verifie_pere(inst2);
Echange_interne_global_impose inst3;verifie_pere(inst3);
Echange_interne_global_parfait inst4;verifie_pere(inst4);
Pb_Conduction inst5;verifie_pere(inst5);
Solide inst6;verifie_pere(inst6);
Traitement_particulier_Solide inst7;verifie_pere(inst7);
}
