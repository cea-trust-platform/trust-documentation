//
// Warning : DO NOT EDIT ! file generated automatically
// TRUST_NO_INDENT
//
#include <verifie_pere.h>
#include <Coarsen_Operator_K.h>
#include <Coarsen_Operator_Uniform.h>
#include <IJK_Test_Multigrille.h>
#include <Multigrille_Adrien.h>
#include <Test_SSE_Kernels.h>
void instancie_src_IJK_Multigrille() {
Cerr << "src_IJK_Multigrille" << finl;
Coarsen_Operator_K inst1;verifie_pere(inst1);
Coarsen_Operator_Uniform inst2;verifie_pere(inst2);
IJK_Test_Multigrille inst3;verifie_pere(inst3);
Multigrille_Adrien inst4;verifie_pere(inst4);
Test_SSE_Kernels inst5;verifie_pere(inst5);
}
