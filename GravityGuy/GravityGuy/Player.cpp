/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#include "Player.h"
#include "GravityGuy.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    
    // sequências de animação do player
    tilesetRun = new TileSet("Resources/Personagem/Run.png", 200, 200, 8, 8);
    uint run[8] = { 1,2,3,4,5,6,7,8};              // animação de correr
    animRun = new Animation(tilesetRun, 0.120f, true);
    animRun->Add(RUNING, run, 8);
    
    tilesetIdle = new TileSet("Resources/Personagem/Idle.png", 200, 200, 8, 8);
    uint idle[8] = { 1,2,3,4,5,6,7,8};             // animação parado
    animIdle = new Animation(tilesetIdle, 0.120f, true);
    animIdle->Add(IDLE, idle, 8);

    tilesetJump = new TileSet("Resources/Personagem/Jump.png", 200, 200, 2, 2);
    uint jump[2] = { 1,2};                         // animação pulando
    animJump = new Animation(tilesetJump, 0.120f, true);
    animJump->Add(JUMPING, jump, 2);

    tilesetFall = new TileSet("Resources/Personagem/Fall.png", 200, 200, 2, 2);
    uint fall[2] = { 1,2 };                        // animação caindo
    animFall = new Animation(tilesetJump, 0.120f, true);
    animFall->Add(FALLING, fall, 2);

    tilesetAtck1 = new TileSet("Resources/Personagem/Attack1.png", 200, 200, 8, 8);
    uint atck1[8] = { 1,2,3,4,5,6,7,8};            // animação atacando
    animAtck1 = new Animation(tilesetJump, 0.120f, true);
    animAtck1->Add(ATCK_1, atck1, 8);

    tilesetAtck2 = new TileSet("Resources/Personagem/Attack2.png", 200, 200, 8, 8);
    uint atck2[8] = { 1,2,3,4,5,6,7,8};            // animação atacando
    animAtck2 = new Animation(tilesetJump, 0.120f, true);
    animAtck2->Add(ATCK_2, atck2, 8);

    tilesetDeath = new TileSet("Resources/Personagem/Death.png", 200, 200, 8, 8);
    uint death[8] = { 1,2,3,4,5,6,7,8 };           // animação morrendo
    animDeath = new Animation(tilesetJump, 0.120f, true);
    animDeath->Add(DEATH, death, 8);

    tilesetTakeHit1 = new TileSet("Resources/Personagem/TakeHit.png", 200, 200, 4, 4);
    uint takeHit1[4] = { 1,2,3,4};                 // animação tomando hit
    animTH1 = new Animation(tilesetJump, 0.120f, true);
    animTH1->Add(TAKE_HIT_1, takeHit1, 4);

    tilesetTakeHit2 = new TileSet("Resources/Personagem/TakeHit2.png", 200, 200, 4, 4);
    uint takeHit2[4] = { 1,2,3,4};                 // animação tomando hit
    animTH2 = new Animation(tilesetJump, 0.120f, true);
    animTH2->Add(TAKE_HIT_2, takeHit2, 4);

    //anim->Add(INVERTED, invert, 4);
    //anim->Add(NORMAL, normal, 4);


    // cria bounding box
    BBox(new Rect(
        -1.0f * tilesetIdle->TileWidth() / 7.0f,
        -1.0f * tilesetIdle->TileHeight() / 7.0f,
        tilesetIdle->TileWidth() / 10.0f,
        tilesetIdle->TileHeight() / 9.0f));
    
    // inicializa estado do player
    state = IDLE;  
    level = 0;

    // posição inicial
    MoveTo(window->CenterX(), 100.0f, Layer::FRONT); 
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete animRun;
    delete animFall;
    delete animTH1;
    delete animTH2;
    delete animIdle;
    delete animJump;
    delete animAtck1;
    delete animAtck2;
    delete animDeath;
    delete tilesetJump;
    delete tilesetFall;
    delete tilesetTakeHit1;
    delete tilesetTakeHit2;
    delete tilesetAtck1;
    delete tilesetAtck2;
    delete tilesetIdle;
    delete tilesetDeath;
    delete tilesetRun;
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    state = IDLE;
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == FINISH)
    {
        // chegou ao final do nível
        level++;
    }
    //else
    {
        // mantém personagem em cima da plataforma
      //  if (gravity == NORMAL)
          //  MoveTo(window->CenterX(), obj->Y() - 32);
        //else
            //MoveTo(window->CenterX(), obj->Y() + 32);
    }

    // ----------------------------------------------------------
    // Processa teclas pressionadas
    // ----------------------------------------------------------
    // jogador só pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, não é possível a mudança no ar
    // ----------------------------------------------------------

    /*if (window->KeyPress(VK_SPACE))
    {
        gravity = !gravity;

        // toca efeito sonoro
        GravityGuy::audio->Play(TRANSITION);

        // tira player da plataforma para evitar 
        // detecção de colisão no quadro seguinte
        if (gravity == NORMAL)
            Translate(0, 12);
        else
            Translate(0 , -12);
    }*/
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    
    // atualiza animação
    animIdle->Select(state);
    animIdle->NextFrame();
}

// ---------------------------------------------------------------------------------