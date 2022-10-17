/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#include "NinjaHeroe.h"
#include "Home.h"
#include "FortOfIllusion.h"
#include "Player.h"
#include "FortOfIllusionBG.h"
#include "Object.h"


#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

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
    Firewarrior = new FireWarrior();
    ground = new Ground(new Point(1.0f, window->CenterY() + 75), new Point(195.0f, window->CenterY() + 75));
    ground2 = new Ground(new Point(195.0f, window->CenterY() + 75), new Point(195.0f, window->CenterY() + 50));


    scene->Add(ground, MOVING);
    scene->Add(ground2, MOVING);
    
    //
    //scene->Add(backg, STATIC);
    //// adiciona jogador na cena
    scene->Add(NinjaHeroe::player, MOVING);
    NinjaHeroe::player->MoveTo(130, window->CenterY() + 45);

    scene->Add(worm, MOVING);
    worm->MoveTo(10, window->CenterY() + 45);
    scene->Add(worm->fireball, MOVING);
    scene->Add(Firewarrior, MOVING);
    //

    // ----------------------
    // plataformas
    // ----------------------

    
    // ----------------------

    // inicia com música
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
