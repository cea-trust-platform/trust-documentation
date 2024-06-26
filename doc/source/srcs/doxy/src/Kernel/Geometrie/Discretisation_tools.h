/****************************************************************************
* Copyright (c) 2023, CEA
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

#ifndef Discretisation_tools_included
#define Discretisation_tools_included

#include <TRUSTTabs_forward.h>
class Champ_base;
class Domaine_VF;

/*! @brief : class Discretisation_tools
 *
 *  Useful interpolation methods !
 *
 */

class Discretisation_tools
{
public :
  static void nodes_to_cells(const Champ_base& Hn,  Champ_base& He);
  static void cells_to_nodes(const Champ_base& He,  Champ_base& Hn);
  static void faces_to_cells(const Champ_base& Hf,  Champ_base& He);
  static void cells_to_faces(const Champ_base& He,  Champ_base& Hf);

  static void cells_to_faces(const Domaine_VF& , const DoubleTab& , DoubleTab& );
  static void faces_to_cells(const Domaine_VF& , const DoubleTab& , DoubleTab& );

};

#endif /* Discretisation_tools_included */
