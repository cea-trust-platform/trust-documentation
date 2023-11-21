//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Boundary_Conditions.h>
#include <Boundary_Conditions_Thermique.h>
#include <DebogIJK.h>
#include <IJK_Grid_Geometry.h>
#include <IJK_Lata_Swap_JK.h>
#include <IJK_Splitting.h>
#include <IJK_discretization.h>
#include <Parallel_io_parameters.h>
void instancie_src_IJK_Framework() {
Cerr << "src_IJK_Framework" << finl;
Boundary_Conditions inst1;verifie_pere(inst1);
Boundary_Conditions_Thermique inst2;verifie_pere(inst2);
DebogIJK inst3;verifie_pere(inst3);
IJK_Grid_Geometry inst4;verifie_pere(inst4);
IJK_Lata_Swap_JK inst5;verifie_pere(inst5);
IJK_Splitting inst6;verifie_pere(inst6);
IJK_discretization inst7;verifie_pere(inst7);
Parallel_io_parameters inst8;verifie_pere(inst8);
}
