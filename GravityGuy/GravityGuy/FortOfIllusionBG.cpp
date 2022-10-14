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

FortOfIllusionBG::FortOfIllusionBG(Color tint) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);

    //carrega as imagens
    imgF = new Image("Resources/BG/Lights.png");
    imgM = new Image("Resources/BG/forestMiddleTrees.png");
    imgL = new Image("Resources/BG/forestFrontTrees.png");
    imgB = new Image("Resources/BG/forestBackTrees.png");

    // cria plano de fundo
    backbg = new Sprite(imgB);
    lowerbg = new Sprite(imgL);
    midlebg = new Sprite(imgM);
    frontbg = new Sprite(imgF);
  }

// ---------------------------------------------------------------------------------

FortOfIllusionBG::~FortOfIllusionBG()
{
    delete imgF;
    delete imgB;
    delete imgM;
    delete imgL;
    delete backbg;
    delete lowerbg;
    delete midlebg;
    delete frontbg;
}

// -------------------------------------------------------------------------------

void FortOfIllusionBG::Update()
{

}

// -------------------------------------------------------------------------------

void FortOfIllusionBG::Draw()
{
    backbg->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 3.0f, 0.0f, color);
    lowerbg->Draw(window->CenterX(), window->CenterY(), Layer::LOWER, 3.0f, 0.0f, color);
    midlebg->Draw(window->CenterX(), window->CenterY(), Layer::MIDDLE, 3.0f, 0.0f, color);
    frontbg->Draw(window->CenterX(), window->CenterY(), Layer::FRONT, 3.0f, 0.0f, color);
}

// -------------------------------------------------------------------------------
