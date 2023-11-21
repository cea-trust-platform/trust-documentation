//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Source_Generique_Face_PolyMAC.h>
#include <Terme_Boussinesq_PolyMAC_Face.h>
#include <Terme_Puissance_Thermique_Echange_Impose_Elem_PolyMAC.h>
#include <Terme_Source_Decroissance_Radioactive_Elem_PolyMAC.h>
#include <Terme_Source_Qdm_Face_PolyMAC.h>
#include <Terme_Source_Qdm_Face_PolyMAC_P0P1NC.h>
void instancie_src_PolyMAC_Sources() {
Cerr << "src_PolyMAC_Sources" << finl;
Source_Generique_Face_PolyMAC inst1;verifie_pere(inst1);
Source_Generique_Face_PolyMAC_P0P1NC inst2;verifie_pere(inst2);
Terme_Boussinesq_PolyMAC_Face inst3;verifie_pere(inst3);
Terme_Puissance_Thermique_Echange_Impose_Elem_PolyMAC inst4;verifie_pere(inst4);
Terme_Source_Decroissance_Radioactive_Elem_PolyMAC inst5;verifie_pere(inst5);
Terme_Source_Qdm_Face_PolyMAC inst6;verifie_pere(inst6);
Terme_Source_Qdm_Face_PolyMAC_P0P1NC inst7;verifie_pere(inst7);
}
