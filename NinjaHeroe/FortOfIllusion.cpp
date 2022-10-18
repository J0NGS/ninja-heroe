/**********************************************************************************
// Level1 (C�digo Fonte)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Nível 1 do jogo
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

Scene* FortOfIllusion::scene        = nullptr;      //
Worm* FortOfIllusion::worm          = nullptr;      //
Fireball* FortOfIllusion::fireball = nullptr;      //
FireWarrior* FortOfIllusion::Firewarrior  = nullptr;      //

// ------------------------------------------------------------------------------

FortOfIllusion::FortOfIllusion(){
    scene       = new Scene();
    backg       = new FortOfIllusionBG();
    worm        = new Worm(NinjaHeroe::player->X() + 90, NinjaHeroe::player->Y());
    brickSpeed = 400;
    brickVoid = new Brick("Resources/FortOfIllusion/layers/BrickVoid1.png");
    brickVoid->type = BRICKVOID;
    
    brickVoid2 = new Brick("Resources/FortOfIllusion/layers/BrickVoid2.png");
    brickVoid2->type = B;

    brick1      = new Brick("Resources/FortOfIllusion/layers/Bloco1.png");
    brick2      = new Brick("Resources/FortOfIllusion/layers/Bloco2.png");
    brick3      = new Brick("Resources/FortOfIllusion/layers/Bloco3.png");
    // tijolo
    brick4      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png");
    brick5      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png");
    brick6      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png");
    brick7      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png");
}
FortOfIllusion::~FortOfIllusion(){}

void FortOfIllusion::Init()
{
    
    // cria gerenciador de cena
    // pano de fundo do jogo
    scene->Add(backg, MOVING);

    // pano de fundo do jogo

    worm->MoveTo(200, window->CenterY() + 80);
    scene->Add(worm, MOVING);
    scene->Add(worm->fireball, MOVING);
    
    //
    //// adiciona jogador na cena
    NinjaHeroe::player->MoveTo(60, window->CenterY() + 20);
    scene->Add(NinjaHeroe::player, MOVING);
    scene->Add(NinjaHeroe::player->lif, STATIC);


    // ----------------------
    // PLATAFORMAS
    // ----------------------
    // 
    brickVoid->MoveTo(844, 519);
    scene->Add(brickVoid, MOVING);
    
    brickVoid2->MoveTo(2570, 562);
    scene->Add(brickVoid2, MOVING);
    // Blocos
    brick1->MoveTo(384, 562);
    scene->Add(brick1, MOVING);
    
    brick2->MoveTo(1662, 562);
    scene->Add(brick2, MOVING);

    brick3->MoveTo(3868, 562);
    scene->Add(brick3, MOVING);
    
    // Tijolos
    brick4->MoveTo(844, 352);
    scene->Add(brick4, MOVING);

    brick5->MoveTo(844, 352);
    scene->Add(brick5, MOVING);

    brick6->MoveTo(844, 352);
    scene->Add(brick6, MOVING);

    brick7->MoveTo(844, 352);
    scene->Add(brick7, MOVING);
    // ----------------------
}
// ------------------------------------------------------------------------------
void FortOfIllusion::Update()
{


    if (!NinjaHeroe::player->jumping && window->KeyDown(VK_RIGHT)) {
        backg->posX -= brickSpeed * gameTime;
        brickVoid->Translate(-brickSpeed * gameTime, 0);
        brickVoid2->Translate(-brickSpeed * gameTime, 0);

        brick1->Translate(-brickSpeed * gameTime, 0);
        brick2->Translate(-brickSpeed * gameTime, 0);
        brick3->Translate(-brickSpeed * gameTime, 0);
        brick4->Translate(-brickSpeed * gameTime, 0);
        brick5->Translate(-brickSpeed * gameTime, 0);
        brick6->Translate(-brickSpeed * gameTime, 0);
        brick7->Translate(-brickSpeed * gameTime, 0);

    }

    
    if (!NinjaHeroe::player->jumping && window->KeyDown(VK_LEFT) && backg->posX < 2500) {
        backg->posX += brickSpeed * gameTime;
        brickVoid->Translate(brickSpeed * gameTime, 0);
        brickVoid2->Translate(brickSpeed * gameTime, 0);

        brick1->Translate(brickSpeed * gameTime, 0);
        brick2->Translate(brickSpeed * gameTime, 0);
        brick3->Translate(brickSpeed * gameTime, 0);
        brick4->Translate(brickSpeed * gameTime, 0);
        brick5->Translate(brickSpeed * gameTime, 0);
        brick6->Translate(brickSpeed * gameTime, 0);
        brick7->Translate(brickSpeed * gameTime, 0);

    }
    // é pq mexe o fundo e o brick fica parado, o brick tem que acompanhar o fundo no caso
    if (window->KeyPress(VK_DOWN)) {
        //NinjaHeroe::player->MoveTo(NinjaHeroe::player->X(), NinjaHeroe::player->Y() + 1);         //errado

    }
    //comando para animação quando aperta para a direita

    
    if (!NinjaHeroe::player->jumping && window->KeyDown(VK_LEFT) && backg->posX < 2500) {
        backg->posX += brickSpeed * gameTime;
        brickVoid->Translate(brickSpeed * gameTime, 0);
        brickVoid2->Translate(brickSpeed * gameTime, 0);

        brick1->Translate(brickSpeed * gameTime, 0);
        brick2->Translate(brickSpeed * gameTime, 0);
        brick3->Translate(brickSpeed * gameTime, 0);
        brick4->Translate(brickSpeed * gameTime, 0);
        brick5->Translate(brickSpeed * gameTime, 0);
        brick6->Translate(brickSpeed * gameTime, 0);
        brick7->Translate(brickSpeed * gameTime, 0);
    }
    // é pq mexe o fundo e o brick fica parado, o brick tem que acompanhar o fundo no caso
    if (window->KeyPress(VK_UP)) {
        NinjaHeroe::player->jumping = true;
        NinjaHeroe::player->jumpTimer->Start();
        //NinjaHeroe::player->MoveTo(NinjaHeroe::player->X(), NinjaHeroe::player->Y() + 1);         //errado

    }
    //comando para animação quando aperta para a direita
    
    
    if (worm->fireball->X() > window->Width()) {
        worm->fireball->shootOff();
    }

    if (worm->fireball->shoot == false) {
        scene->Remove(worm->fireball, MOVING);
        delete worm->fireball;
        worm->fireball = new Fireball();
        scene->Add(worm->fireball, MOVING);
    }
    
    scene->Update();
    scene->CollisionDetection();
}

// ------------------------------------------------------------------------------

void FortOfIllusion::Draw()
{   
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
