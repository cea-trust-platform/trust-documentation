//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Correction_Antal_VDF.h>
#include <Dispersion_bulles_VDF.h>
#include <Flux_interfacial_VDF.h>
#include <Force_Tchen_VDF.h>
#include <Frottement_interfacial_VDF.h>
#include <Op_Evanescence_Homogene_VDF_Elem.h>
#include <Op_Evanescence_Homogene_VDF_Face.h>
#include <Portance_interfaciale_VDF.h>
#include <Travail_pression_VDF.h>
void instancie_src_VDF_Multiphase() {
Cerr << "src_VDF_Multiphase" << finl;
Correction_Antal_VDF inst1;verifie_pere(inst1);
Dispersion_bulles_VDF inst2;verifie_pere(inst2);
Flux_interfacial_VDF inst3;verifie_pere(inst3);
Force_Tchen_VDF inst4;verifie_pere(inst4);
Frottement_interfacial_VDF inst5;verifie_pere(inst5);
Op_Evanescence_Homogene_VDF_Elem inst6;verifie_pere(inst6);
Op_Evanescence_Homogene_VDF_Face inst7;verifie_pere(inst7);
Portance_interfaciale_VDF inst8;verifie_pere(inst8);
Travail_pression_VDF inst9;verifie_pere(inst9);
}
