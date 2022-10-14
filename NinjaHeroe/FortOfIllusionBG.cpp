/**********************************************************************************
// Background (Código Fonte)
//
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "FortOfIllusionBG.h"

// ---------------------------------------------------------------------------------

FortOfIllusionBG::FortOfIllusionBG() {
    mountainImg = new Image("Resources/FortOfIllusion/Layers/mountains.png");
    for (int i = 0; i < 7; i++) {
        mountains[i] = new Sprite(mountainImg);
    }
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

    for (int i = 0; i < 7; i++) {
        mountains[i]->Draw(i * 384, window->CenterY(), Layer::BACK, 1.5);
        //mountains[i]->Draw((i * 384), window->CenterY() + 50, Layer::BACK, 1.5); -----> AJEITAR FUNDO
    }
    // Front mountains
}

// -------------------------------------------------------------------------------
void FortOfIllusionBG::Finalize() {
    delete mountainImg;
    delete mountains;
    
}