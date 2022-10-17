/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "NinjaHeroe.h"
#include "Home.h"
#include "FortOfIllusion.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    backg = new Sprite("Resources/Home/Background.jpg");
    tileset = new TileSet("Resources/PressEnter.png", 72, 48, 1, 5);
    anim = new Animation(tileset, 0.180f, true);
    //NinjaHeroe::audio->Play(MENU, true);
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    // se a tecla ENTER for pressionada
    if (window->KeyPress(VK_RETURN))
    {
       // NinjaHeroe::audio->Stop(MENU);
       NinjaHeroe::NextLevel<FortOfIllusion>();
    }
    else
    {
        anim->NextFrame();
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    anim->Draw(545, 275);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete anim;
    delete tileset;
    delete backg;
}

// ------------------------------------------------------------------------------