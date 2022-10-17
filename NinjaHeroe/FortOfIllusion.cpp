/**********************************************************************************
// Level1 (C�digo Fonte)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo
//
**********************************************************************************/

#include "NinjaHeroe.h"
#include "Home.h"
#include "FortOfIllusion.h"
#include "Player.h"
#include "FortOfIllusionBG.h"
#include "Object.h"
#include "Brick.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene* FortOfIllusion::scene        = nullptr;      //
Worm* FortOfIllusion::worm          = nullptr;      //
Fireball* FortOfIllusion::fireball = nullptr;      //
FireWarrior* FortOfIllusion::Firewarrior  = nullptr;      //

// ------------------------------------------------------------------------------

void FortOfIllusion::Init()
{

    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new FortOfIllusionBG();

    worm = new Worm(NinjaHeroe::player->X() + 90, NinjaHeroe::player->Y());

    //
    //scene->Add(backg, STATIC);
    //// adiciona jogador na cena
    scene->Add(NinjaHeroe::player, MOVING);
    NinjaHeroe::player->MoveTo(130, window->CenterY() + 45);
    scene->Add(NinjaHeroe::player->life, STATIC);

    scene->Add(worm, MOVING);
    worm->MoveTo(10, window->CenterY() + 45);
    scene->Add(worm->fireball, MOVING);
    scene->Add(Firewarrior, MOVING);
    //

    // ----------------------
    // plataformas
    // ----------------------
    Brick* brick = new Brick("Resources/FortOfIllusion/layers/Bloco1.png");
    brick->MoveTo(48, 421);
    scene->Add(brick, MOVING);

    
    // ----------------------

    // inicia com m�sica
    /*NinjaHeroe::audio->Frequency(MUSIC, 0.94f);
    NinjaHeroe::audio->Frequency(TRANSITION, 1.0f);
    NinjaHeroe::audio->Play(MUSIC);*/

}

// ------------------------------------------------------------------------------

void FortOfIllusion::Update()
{

    if (window->KeyPress(VK_DOWN)) {
        //NinjaHeroe::player->MoveTo(NinjaHeroe::player->X(), NinjaHeroe::player->Y() + 1);         //errado

    }
    if (window->KeyDown(VK_RIGHT)) {
        //NinjaHeroe::player->MoveTo(NinjaHeroe::player->X() + 50 * gameTime, NinjaHeroe::player->Y());       //errado
    }
    
    if (worm->fireball->X() > window->Width()) {
        
        worm->fireball->shootOff();
        delete worm->fireball;
        worm->fireball = new Fireball();
    }
    
    scene->Update();
    scene->CollisionDetection();
}

// ------------------------------------------------------------------------------

void FortOfIllusion::Draw()
{   
    backg->Draw();
    scene->Draw();

    if (NinjaHeroe::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void FortOfIllusion::Finalize()
{
    scene->Remove(NinjaHeroe::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------
