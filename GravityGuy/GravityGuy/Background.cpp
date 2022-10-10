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

// ---------------------------------------------------------------------------------

Background::Background(Color tint) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = xB = x;

    // carrega imagens
    imgF = new Image("Resources/BG/forestFrontTrees.png");
    imgB = new Image("Resources/BG/forestBackTrees.png");
    imgM = new Image("Resources/BG/forestMiddleTress.png");
    //desenha bg
    bgB = new Sprite(imgB);
    bgM = new Sprite(imgM);
    bgF = new Sprite(imgF);

    
    // cria sprites do plano de fundo
/*sky = new Sprite("Resources/Sky.png");
    backgF1 = new Sprite(imgF);
    backgF2 = new Sprite(imgF);
    backgB1 = new Sprite(imgB);
    backgB2 = new Sprite(imgB);
*/
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete imgF;
    delete imgB;    
    delete imgM;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    // move sprites com velocidades diferentes
    //xF -= 200 * gameTime;
    //xB -= 150 * gameTime;
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    // desenha pano de fundo
    bgB->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 2.5f, 0.0f, color);
    bgM->Draw(window->CenterX(), window->CenterY(), Layer::MIDDLE, 2.5f, 0.0f, color);
    bgF->Draw(window->CenterX(), window->CenterY(), Layer::FRONT, 2.5f, 0.0f, color);

    // desenha prédios mais distantes
    //backgB1->Draw(xB, y, Layer::LOWER, 1.0f, 0.0f, color);
    //backgB2->Draw(xB + imgB->Width(), y, Layer::LOWER, 1.0f, 0.0f, color);
    
    // traz pano de fundo de volta para dentro da tela
    //if (xB + imgB->Width()/2.0f < 0)
        //xB += imgB->Width();

    // desenha prédios mais próximos
    //backgF1->Draw(xF, y, Layer::MIDDLE, 1.0f, 0.0f, color);
    //backgF2->Draw(xF + imgF->Width(), window->Height()/2.0f, Layer::MIDDLE, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    //if (xF + imgF->Width()/2.0f < 0)
        //xF += imgF->Width();
}

// -------------------------------------------------------------------------------
