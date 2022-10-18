/**********************************************************************************
// Background (C�digo Fonte)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#include "FortOfIllusionBG.h"
#include "NinjaHeroe.h"

// ---------------------------------------------------------------------------------

FortOfIllusionBG::FortOfIllusionBG() {
    posX = 2500;
    posY = window->CenterY();
    MoveTo(posX, posY, Layer::BACK);
    fortOfIllusion  = new Sprite("Resources/FortOfIllusion/Previews/esqueleto.jpg");
   
}
// ---------------------------------------------------------------------------------

FortOfIllusionBG::~FortOfIllusionBG()
{
    
}

// -------------------------------------------------------------------------------

void FortOfIllusionBG::Update()
{
    
}

// -------------------------------------------------------------------------------

void FortOfIllusionBG::Draw()
{
    fortOfIllusion->Draw(posX, posY, Layer::BACK);
}

// -------------------------------------------------------------------------------
void FortOfIllusionBG::Finalize() {
    delete fortOfIllusion;
}