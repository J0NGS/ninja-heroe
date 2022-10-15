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


#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene* FortOfIllusion::scene = nullptr;
Worm* FortOfIllusion::worm = nullptr;
Fireball* FortOfIllusion::fireball= nullptr;

// ------------------------------------------------------------------------------

void FortOfIllusion::Init()
{

    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new FortOfIllusionBG();

    worm = new Worm(NinjaHeroe::player->X() + 90, NinjaHeroe::player->Y());
    ground = new Ground(new Point(1.0f, window->CenterY() + 75), new Point(195.0f, window->CenterY() + 75));
    ground2 = new Ground(new Point(195.0f, window->CenterY() + 75), new Point(195.0f, window->CenterY() + 50));


    scene->Add(ground, MOVING);
    scene->Add(ground2, MOVING);

    //
    //scene->Add(backg, STATIC);
    //// adiciona jogador na cena
    scene->Add(NinjaHeroe::player, MOVING);
    NinjaHeroe::player->MoveTo(30, window->CenterY() + 45);
    scene->Add(worm, MOVING);
    //

    // ----------------------
    // plataformas
    // ----------------------

    
    // ----------------------

    // inicia com m�sica
    /*NinjaHeroe::audio->Frequency(MUSIC, 0.94f);
    NinjaHeroe::audio->Frequency(TRANSITION, 1.0f);
    NinjaHeroe::audio->Play(MUSIC);*/

}

// ------------------------------------------------------------------------------

void FortOfIllusion::Update()
{
    {
        scene->Update();
        scene->CollisionDetection();
    }
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
