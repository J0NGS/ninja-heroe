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

#include "FireWarrior.h"
#include "NinjaHeroe.h"

// ---------------------------------------------------------------------------------

FireWarrior::FireWarrior()
{
    //inicializa o tipo do objeto
    type = FIREWARRIOR;

    //instanciando tilesets e animações
    tilesetRun = new TileSet("Resources/FireWarrior/Run/Run.png", 115, 80, 8, 8);
    animRun = new Animation(tilesetRun, 0.240, true);

    tilesetJump = new TileSet("Resources/Personagem/Jump.png", 200, 200, 2, 2);
    animJump = new Animation(tilesetJump, 0.240f, true);

    tilesetIdle = new TileSet("Resources/FireWarrior/Idle/Idle.png", 115, 80, 8, 8);
    animIdle = new Animation(tilesetIdle, 0.120f, true);

    tilesetDeath = new TileSet("Resources/Personagem/Death.png", 200, 200, 6, 6);
    animDeath = new Animation(tilesetDeath, 0.120f, false);

    tilesetAtck = new TileSet("Resources/FireWarrior/Attack/Attack.png", 115, 80, 8, 8);
    animAtck = new Animation(tilesetAtck, 0.150f, false);
    
    //sequencia de animações
    uint run[8] = { 1,2,3,4,5,6,7,8 };
    uint jump[3] = { 1,2,3};
    uint idle[8] = { 1,2,3,4,5,6,7,8};
    uint death[11] = {1,2,3,4,5,6,7,8,9,10,11};
    uint atck1[4] = { 1,2,3,4};
    uint atck2[4] = { 5,6,7,8};
    uint take[1] = {};

    //adicionando sequencias nas animações
    animIdle->Add(IDLE, idle, 8);
    animJump->Add(JUMPING, jump, 3);
    animRun->Add(RUNING, run, 8);
    animDeath->Add(DEATH, death, 11);
    animAtck->Add(ATCK1, atck1, 4);
    animAtck->Add(ATCK2, atck2, 5);

    
    // inicializa estado do player
    state = ATCK1;
    // posição inicial
    MoveTo(window->CenterX() + 90, window->CenterY() - (window->CenterY() / 2), Layer::FRONT);
}

// ---------------------------------------------------------------------------------

FireWarrior::~FireWarrior()
{
    delete animRun;
    delete animJump;
    delete animIdle;
    delete animDeath;
    delete animAtck;
    delete animHit;
    delete animFall;
    delete tilesetRun;
    delete tilesetJump;
    delete tilesetIdle;
    delete tilesetDeath;
    delete tilesetAtck;
    delete tilesetTake;
    delete tilesetFall;
}

// ---------------------------------------------------------------------------------



// ---------------------------------------------------------------------------------

void FireWarrior::OnCollision(Object* obj)
{
}

// ---------------------------------------------------------------------------------

void FireWarrior::Update()
{
    //comando para animação quando aperta para correr
    if (state == RUNING) {
        animRun->Select(state);
        animRun->NextFrame();
    }
    //------------------------------------------------------
    //comando para animação quando aperta para pular
    if (state == JUMPING) {
        animJump->Select(state);
        animJump->NextFrame();
    }
    //------------------------------------------------------
    //comando para animação ataque 1 e ataque
    if (state == ATCK1) {
        animAtck->Select(state);
        animAtck->NextFrame();
        if (animAtck->Inactive())
            state = ATCK2;  
    }
    if (state == ATCK2) {
        animAtck->Restart();
        animAtck->Select(state);
        animAtck->NextFrame();
    if (animAtck->Inactive())
        state = IDLE;
    }
    //------------------------------------------------------
    //enquanto está parado roda a animação
    if (state == IDLE) {
        animIdle->Select(state);
        animIdle->Restart();
        animIdle->NextFrame();
    }
}

// ---------------------------------------------------------------------------------

void FireWarrior::Draw()
{
    switch (state)
    {
    case JUMPING:
        animJump->Draw(x, y, z, 1.5f);
        break;

    case RUNING:
        animRun->Draw(x, y, z, 1.5f);
        break;

    case IDLE:
        animIdle->Draw(x, y, z, 1.5f);
        break;

    case ATCK1:
        animAtck->Draw(x, y, z, 1.5f);
        break;

    case ATCK2:
        animAtck->Draw(x, y, z, 1.5f);
        break;
    }
}

// ---------------------------------------------------------------------------------