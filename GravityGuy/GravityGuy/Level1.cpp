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
#include "Level1.h"
#include "Player.h"
#include "Background.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background(Color{ 1,1,1,1 });
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(NinjaHeroe::player, MOVING);

    // ----------------------
    // plataformas
    // ----------------------

    
    // ----------------------

    // inicia com música
    NinjaHeroe::audio->Frequency(MUSIC, 0.94f);
    NinjaHeroe::audio->Frequency(TRANSITION, 1.0f);
    NinjaHeroe::audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    backg->Draw();
    scene->Draw();

    if (NinjaHeroe::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(NinjaHeroe::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------
