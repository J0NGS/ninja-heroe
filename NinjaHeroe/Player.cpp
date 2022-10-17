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
#include "NinjaHeroe.h"
#include <sstream>
using namespace std;

// ---------------------------------------------------------------------------------

Player::Player()
{

    jumpTimer = new Timer();
    // ---------------------------------Controls------------------------------------
    right = false;
    left = false;
    up = false;
    space = false;
    // -------------------------------Atributes-------------------------------------
    //tipo
    type = PLAYER;
    
    // inicializa estado do player
    state = IDLE;
    level = 0;
    life = new Life(400);
    speed = 30;


    // posição inicial
    MoveTo(window->CenterX(), window->CenterY(), Layer::FRONT);

    // ------------------------Tileset&Animation------------------------------------
    tilesetRun = new TileSet("Resources/Personagem/Run.png", 200, 200, 16, 16);
    animRun = new Animation(tilesetRun, 0.120f, true);

    tilesetJump = new TileSet("Resources/Personagem/Jump.png", 200, 200, 2, 2);
    animJump = new Animation(tilesetJump, 0.240f, false);

    tilesetIdle = new TileSet("Resources/Personagem/Idle.png", 200, 200, 8, 8);
    animIdle = new Animation(tilesetIdle, 0.120f, true);

    tilesetDeath = new TileSet("Resources/Personagem/Death.png", 200, 200, 6, 6);
    animDeath = new Animation(tilesetDeath, 0.120f, false);

    tilesetAtck = new TileSet("Resources/Personagem/Attack.png", 200, 200, 24, 24);
    animAtck = new Animation(tilesetAtck, 0.150f, false);
    
    tilesetTake = new TileSet("Resources/Personagem/TakeHit.png", 200, 200, 8, 8);
    animTake = new Animation(tilesetTake, 0.150f, false);

    tilesetFall = new TileSet("Resources/Personagem/Fall.png", 200, 200, 2, 2);
    animFall = new Animation(tilesetFall, 0.120f, false);
   

    // ------------------------SequenAnimation-------------------------------------
    uint run[8] = { 0,1,2,3,4,5,6,7 };
    uint runLeft[8] = { 15,14,13,11,11,10,9,8};
    uint jump[2] = { 0,1 };
    uint idle[8] = { 0,1,2,3,4,5,6,7};
    uint death[6] = { 0,1,2,3,4,5};
    uint atck1[6] = { 0,1,2,3,4,5};
    uint atck2[6] = { 6,7,8,9,10,11 };
    uint take[4] = { 0,1,2,3};
    uint fall[8] = { 0,1,2,3,4,5,6,7};

 
    
    //adicionando sequencias nas animações
    animIdle->Add(IDLE, idle, 8);
    animJump->Add(JUMPING, jump, 2);
    animRun->Add(RUNING, run, 8);
    animRun->Add(RUNINGLEFT, runLeft, 8);
    animDeath->Add(DEATH, death, 6);
    animAtck->Add(ATCK1, atck1, 6);
    animAtck->Add(ATCK2, atck2, 6);
    animAtck->Add(ATCK1LEFT, atck2, 6);
    animAtck->Add(ATCK2LEFT, atck2, 6);
    animTake->Add(TAKEHIT, take, 4);
    
    
    // ------------------------------BoundBox------------------------------------
    BBox(new Rect(
        -1.0f * tilesetRun->TileWidth() / 7.0f,
        -1.0f * tilesetRun->TileHeight() / 8.0f,
        tilesetRun->TileWidth() / 7.0f,
        tilesetRun->TileHeight() / 8.0f));


}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete animRun;
    delete animJump;
    delete animIdle;
    delete animDeath;
    delete animAtck;
    delete animTake;
    delete animFall;
    delete tilesetRun;
    delete tilesetJump;
    delete tilesetIdle;
    delete tilesetDeath;
    delete tilesetAtck;
    delete tilesetTake;
    delete tilesetFall;
    delete life;
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), window->CenterY() + (window->CenterY() / 2), Layer::FRONT);
    state = IDLE;
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
    if (obj->Type() == FIREBALL) {
        Translate(speed * gameTime, 0);
        state = TAKEHIT;    
        life->Damage(100);
    }
    if (obj->Type() == BRICK) {
        up = false;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{   

    // comando para animação quando aperta para a direita
    if (right && window->KeyUp(VK_RIGHT)) {
        right = false;
        state = IDLE;
    }
    else if (window->KeyDown(VK_RIGHT)) {
        state = RUNING;
        right = true;
        animRun->Select(state);
        animRun->NextFrame();
    }

    // comando para animação quando aperta para a esquerda
    if (left && window->KeyUp(VK_LEFT)) {
        left = false;
        state = IDLE;

    }
    else if (window->KeyDown(VK_LEFT)) {
        state = RUNINGLEFT;
        left = true;
        animRun->Select(state);
        animRun->NextFrame();
    }
    //------------------------------------------------------
    // comando para animação quando aperta para cima
    if (up && window->KeyUp(VK_UP)) {
        Translate(60 * gameTime, 60 * gameTime); 
        state = IDLE;
    }
    else if (window->KeyDown(VK_UP)) {
        Translate(60 * gameTime, -60 * gameTime);
        
        state = JUMPING;
        up = true;
        animJump->Select(state);
        animJump->NextFrame();
    }
    //------------------------------------------------------
    // comando para animação quando aperta espaço(attack)
    if (space && window->KeyUp(VK_SPACE)) {
        state = IDLE;
        space = false;
        animAtck->Restart();
    }
    else if (window->KeyDown(VK_SPACE)) {
        space = true;
        if(state == IDLE )
            state = ATCK1;
        
        if (state == ATCK1 && animAtck->Inactive()){
            state = ATCK2;
            animAtck->Restart();
            if (animAtck->Inactive())
                state = IDLE;
        }
        animAtck->Select(state);
        animAtck->NextFrame();
    }
    //------------------------------------------------------
    // enquanto está parado roda a animação
    if (state == IDLE) {
        animIdle->Select(state);
        animIdle->NextFrame();
    }
    
    //------------------------------------------------------
    // Animação quando toma um hit
    if (state == TAKEHIT) {
        animTake->Select(state);
        animTake->NextFrame();
    }

    
    //------------------------------------------------------
    //animações da barra de vida
    life->Update();
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    switch (state)
    {
    case JUMPING:
        animJump->Draw(x, y, z, 1.2f);
        break;

    case RUNING:
        animRun->Draw(x, y, z, 1.2f);
        break;

    case RUNINGLEFT:
        animRun->Draw(x, y, z, 1.2f);
        break;

    case ATCK1 :
        animAtck->Draw(x, y, z, 1.2f);
        break;

    case ATCK2:
        animAtck->Draw(x, y, z, 1.2f);
        break;
    case TAKEHIT:
        animTake->Draw(x, y, z, 1.2f);
        break;
    default:
        state = IDLE;
        animIdle->Draw(x, y, z, 1.2f);
        break;
    }

    life->Draw();
}

// ---------------------------------------------------------------------------------