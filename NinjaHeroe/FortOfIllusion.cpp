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
#include <sstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene* FortOfIllusion::scene        = nullptr;      //
Worm* FortOfIllusion::worm          = nullptr;
Worm* FortOfIllusion::worm2 = nullptr;
Worm* FortOfIllusion::worm3 = nullptr;//
Fireball* FortOfIllusion::fireball = nullptr;      //
FireWarrior* FortOfIllusion::Firewarrior  = nullptr;      //

// ------------------------------------------------------------------------------

FortOfIllusion::FortOfIllusion(){
    scene       = new Scene();
    backg       = new FortOfIllusionBG();
    worm        = new Worm(1300, 390);
   
    
    worm2       = new Worm(1600, 390); 
   
    
    worm3       = new Worm(1900, 390);
   
  
    brickSpeed = 200;
    brickVoid = new Brick("Resources/FortOfIllusion/layers/BrickVoid1.png", BRICKVOID);
    
    
    brickVoid2 = new Brick("Resources/FortOfIllusion/layers/BrickVoid2.png", BRICKVOID);
    

    brick1      = new Brick("Resources/FortOfIllusion/layers/Bloco1.png",BRICK);
    brick2      = new Brick("Resources/FortOfIllusion/layers/Bloco2.png", BRICK);
    brick3      = new Brick("Resources/FortOfIllusion/layers/Bloco3.png", BRICK);
    // tijolo
    brick4      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png", MINIBRICK);
    brick5      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png", MINIBRICK);
    brick6      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png", MINIBRICK);
    brick7      = new Brick("Resources/FortOfIllusion/layers/tijolo2.png", MINIBRICK);
}
FortOfIllusion::~FortOfIllusion(){}

void FortOfIllusion::Init()
{
    
    // cria gerenciador de cena
    // pano de fundo do jogo
    scene->Add(backg, MOVING);

    // pano de fundo do jogo
    scene->Add(worm, MOVING);
    scene->Add(worm->fireball, MOVING);
    
    scene->Add(worm2, MOVING);
    scene->Add(worm2->fireball, MOVING);

    scene->Add(worm3, MOVING);
    scene->Add(worm3->fireball, MOVING);

    //
    //// adiciona jogador na cena
    NinjaHeroe::player->MoveTo(60, window->CenterY() + 30);
    scene->Add(NinjaHeroe::player, MOVING);
    scene->Add(NinjaHeroe::player->life, STATIC);


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

    brick5->MoveTo(2000 + 473, 352);
    scene->Add(brick5, MOVING);

    brick6->MoveTo(2100 + 465, 352);
    scene->Add(brick6, MOVING);

    brick7->MoveTo(2200 + 457, 352);
    scene->Add(brick7, MOVING);
    // ----------------------

    // ----------------------
    // inimigos
    // ----------------------
    // worms
}
// ------------------------------------------------------------------------------
void FortOfIllusion::Update()
{
    if (worm->state == DEATH ) {
        scene->Remove(worm, MOVING);
    }
    if (worm2->state == DEATH) {
        scene->Remove(worm2, MOVING);
    }
    if (worm3->state == DEATH) {
        scene->Remove(worm3, MOVING);
    }

    //segurando a tela e movendo o player
 

    if (!NinjaHeroe::player->jumping && NinjaHeroe::player->state != FALLING && window->KeyDown(VK_RIGHT)) {
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
        //----------------inimigos-------------------------
        worm->Translate(-brickSpeed * gameTime, 0);
        worm->fireball->Translate(-brickSpeed * gameTime, 0);

        worm2->Translate(-brickSpeed * gameTime, 0);
        worm2->fireball->Translate(-brickSpeed * gameTime, 0);

        worm3->Translate(-brickSpeed * gameTime, 0);
        worm3->fireball->Translate(-brickSpeed * gameTime, 0);
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
        //----------------inimigos-------------------------
        worm->Translate(brickSpeed * gameTime, 0);
        worm->fireball->Translate(brickSpeed * gameTime, 0);

        worm2->Translate(brickSpeed * gameTime, 0);
        worm2->fireball->Translate(brickSpeed * gameTime, 0);

        worm3->Translate(brickSpeed * gameTime, 0);
        worm3->fireball->Translate(brickSpeed * gameTime, 0);

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
        //----------------inimigos-------------------------
        worm->Translate(brickSpeed * gameTime, 0);
        worm->fireball->Translate(brickSpeed * gameTime, 0);

        worm2->Translate(brickSpeed * gameTime, 0);
        worm2->fireball->Translate(brickSpeed * gameTime, 0);

        worm3->Translate(brickSpeed * gameTime, 0);
        worm3->fireball->Translate(brickSpeed * gameTime, 0);
    }
    // é pq mexe o fundo e o brick fica parado, o brick tem que acompanhar o fundo no caso
    if (window->KeyPress(VK_UP)) {
        NinjaHeroe::player->jumping = true;
        NinjaHeroe::player->jumpTimer->Start();
        //NinjaHeroe::player->MoveTo(NinjaHeroe::player->X(), NinjaHeroe::player->Y() + 1);         //errado

    }
    //comando para animação quando aperta para a direita
    
    
    if (NinjaHeroe::player->Right() == window->Width()) {
        NinjaHeroe::player->MoveTo(1360, NinjaHeroe::player->Y());
    }

    if (worm->fireball->X() > window->Width()) {
        worm->fireball->shootOff();
    }
    if (worm->fireball->X() < 0) {
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
