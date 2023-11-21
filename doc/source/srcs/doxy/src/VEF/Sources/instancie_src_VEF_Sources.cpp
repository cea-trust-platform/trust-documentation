//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Source_Generique_VEF.h>
#include <Source_QC_Chaleur_VEF.h>
#include <Source_QC_Gravite_VEF.h>
#include <Source_QC_VEF_P1NC.h>
#include <Source_WC_Chaleur_VEF.h>
#include <Source_WC_Gravite_VEF.h>
#include <Terme_Boussinesq_VEFPreP1B_Face.h>
#include <Terme_Boussinesq_VEF_Face.h>
#include <Terme_Puissance_Thermique_Echange_Impose_VEF_Face.h>
#include <Terme_Source_Acceleration_VEF_Face.h>
#include <Terme_Source_Canal_RANS_LES_VEF_Face.h>
#include <Terme_Source_Canal_perio_VEF_P1NC.h>
#include <Terme_Source_Decroissance_Radioactive_VEF_Face.h>
#include <Terme_Source_Qdm_VEF_Face.h>
#include <Terme_Source_Qdm_lambdaup_VEF_Face.h>
#include <Terme_Source_Rappel_T_VEF_Face.h>
#include <Terme_Source_Th_TdivU_VEF_Face.h>
void instancie_src_VEF_Sources() {
Cerr << "src_VEF_Sources" << finl;
Source_Generique_VEF inst1;verifie_pere(inst1);
Source_QC_Chaleur_VEF inst2;verifie_pere(inst2);
Source_QC_Gravite_VEF inst3;verifie_pere(inst3);
Acceleration_QC_VEF_P1NC inst4;verifie_pere(inst4);
Perte_Charge_Circulaire_QC_VEF_P1NC inst5;verifie_pere(inst5);
Perte_Charge_Anisotrope_QC_VEF_P1NC inst6;verifie_pere(inst6);
Perte_Charge_Directionnelle_QC_VEF_P1NC inst7;verifie_pere(inst7);
Perte_Charge_Isotrope_QC_VEF_P1NC inst8;verifie_pere(inst8);
Perte_Charge_Reguliere_QC_VEF_P1NC inst9;verifie_pere(inst9);
Perte_Charge_Singuliere_QC_VEF_P1NC inst10;verifie_pere(inst10);
Source_qdm_QC_VEF_P1NC inst11;verifie_pere(inst11);
Darcy_QC_VEF_P1NC inst12;verifie_pere(inst12);
Forchheimer_QC_VEF_P1NC inst13;verifie_pere(inst13);
Source_WC_Chaleur_VEF inst14;verifie_pere(inst14);
Source_WC_Gravite_VEF inst15;verifie_pere(inst15);
Terme_Boussinesq_VEFPreP1B_Face inst16;verifie_pere(inst16);
Terme_Boussinesq_VEF_Face inst17;verifie_pere(inst17);
Terme_Puissance_Thermique_Echange_Impose_VEF_Face inst18;verifie_pere(inst18);
Terme_Source_Acceleration_VEF_Face inst19;verifie_pere(inst19);
Terme_Source_Canal_RANS_LES_VEF_Face inst20;verifie_pere(inst20);
Terme_Source_Canal_perio_VEF_P1NC inst21;verifie_pere(inst21);
Terme_Source_Canal_perio_QC_VEF_P1NC inst22;verifie_pere(inst22);
Terme_Source_Decroissance_Radioactive_VEF_Face inst23;verifie_pere(inst23);
Terme_Source_Qdm_VEF_Face inst24;verifie_pere(inst24);
Terme_Source_Qdm_lambdaup_VEF_Face inst25;verifie_pere(inst25);
Terme_Source_Rappel_T_VEF_Face inst26;verifie_pere(inst26);
Terme_Source_Th_TdivU_VEF_Face inst27;verifie_pere(inst27);
}
