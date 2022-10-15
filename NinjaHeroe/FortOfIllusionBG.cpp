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

// ---------------------------------------------------------------------------------

FortOfIllusionBG::FortOfIllusionBG() {
    fortOfIllusion  = new Sprite("Resources/FortOfIllusion/Previews/FortOfIllusion.png");
    
    /*  
    mountainImg = new Image("Resources/FortOfIllusion/Layers/mountains.png");
    for (int i = 0; i < 7; i++) {
        mountains[i] = new Sprite(mountainImg);
    }*/
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
    fortOfIllusion->Draw(1000, window->CenterY(), Layer::BACK);
}

// -------------------------------------------------------------------------------
void FortOfIllusionBG::Finalize() {
    delete fortOfIllusion;
}