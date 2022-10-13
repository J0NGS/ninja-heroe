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

#include "Background.h"
#include "NinjaHeroe.h"

// ---------------------------------------------------------------------------------

Background::Background(Color tint) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = xM = xB = xL = x;
    moving = false;

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

Background::~Background()
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

void Background::Update()
{
    if (NinjaHeroe::player->Moving()) {
        xF -= 100 * gameTime;
        xB -= 20 * gameTime;
        xM -= 75 * gameTime;
        xL -= 45 * gameTime;
    }
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    frontbg->Draw(xF, window->CenterY(), Layer::FRONT, 3.0f, 0.0f, color);
    // traz pano de fundo de volta para dentro da tela
    if (xF + imgF->Width() / 2.0f < 0)
        xF += imgF->Width();

    backbg->Draw(xB, window->CenterY(), Layer::BACK, 3.0f, 0.0f, color);
    // traz pano de fundo de volta para dentro da tela
    if (xB + imgB->Width() / 2.0f < 0)
        xB += imgB->Width();

    midlebg->Draw(xM, window->CenterY(), Layer::MIDDLE, 3.0f, 0.0f, color);
    // traz pano de fundo de volta para dentro da tela
    if (xM + imgM->Width() / 2.0f < 0)
        xM += imgM->Width();
    
    lowerbg->Draw(xL, window->CenterY(), Layer::LOWER, 3.0f, 0.0f, color);
    // traz pano de fundo de volta para dentro da tela
    if (xL + imgL->Width() / 2.0f < 0)
        xL += imgL->Width();





}

// -------------------------------------------------------------------------------
