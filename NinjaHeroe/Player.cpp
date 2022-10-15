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

// ---------------------------------------------------------------------------------

Player::Player()
{
    //inicializa controles de teclas
    right = false;
    left = false;
    up = false;
    space = false;

    //inicializa o tipo do objeto
    type = PLAYER;

    //instanciando tilesets e animações
    tilesetRun = new TileSet("Resources/Personagem/Run.png", 200, 200, 8, 8);
    animRun = new Animation(tilesetRun, 0.120f, true);

    tilesetJump = new TileSet("Resources/Personagem/Jump.png", 200, 200, 2, 2);
    animJump = new Animation(tilesetJump, 0.240f, true);

    tilesetIdle = new TileSet("Resources/Personagem/Idle.png", 200, 200, 8, 8);
    animIdle = new Animation(tilesetIdle, 0.120f, true);

    tilesetDeath = new TileSet("Resources/Personagem/Death.png", 200, 200, 6, 6);
    animDeath = new Animation(tilesetDeath, 0.120f, false);

    tilesetAtck = new TileSet("Resources/Personagem/Attack.png", 200, 200, 12, 12);
    animAtck = new Animation(tilesetAtck, 0.150f, false);

    //sequencia de animações
    uint run[8] = { 1,2,3,4,5,6,7,8 };
    uint jump[2] = { 1,2 };
    uint idle[8] = { 1,2,3,4,5,6,7,8 };
    uint death[6] = { 1,2,3,4,5,6};
    uint atck1[12] = { 1,2,3,4,5,6};
    uint atck2[6] = {7,8,9,10,11,12};
    uint take[8] = { 1,2,3,4,5,6,7,8 };
    uint fall[8] = { 1,2,3,4,5,6,7,8 };
    
    //adicionando sequencias nas animações
    animRun->Add(IDLE, idle, 8);
    animJump->Add(JUMPING, jump, 2);
    animIdle->Add(RUNING, run, 8);
    animDeath->Add(DEATH, death, 6);
    animAtck->Add(ATCK1, atck1, 6);
    animAtck->Add(ATCK2, atck2, 6);
    
    // cria bounding box
    BBox(new Rect(
        -1.0f * tilesetRun->TileWidth() / 7.0f,
        -1.0f * tilesetRun->TileHeight() / 8.0f,
        tilesetRun->TileWidth() / 7.0f,
        tilesetRun->TileHeight() / 8.0f));

    // inicializa estado do player
    state = IDLE;
    level = 0;
    
    // posição inicial
    MoveTo(window->CenterX(),window->CenterY() + (window->CenterY()/2), Layer::FRONT);
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
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    //comando para animação quando aperta para a direita
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
    //------------------------------------------------------
    //comando para animação quando aperta para cima
    if (up && window->KeyUp(VK_UP)) {
        up = false;
        state = IDLE;
    }
    else if (window->KeyDown(VK_UP)) {
        state = JUMPING;
        up = true;
        animJump->Select(state);
        animJump->NextFrame();
    }
    //------------------------------------------------------
    //comando para animação quando aperta espaço(attack)
    if (space && window->KeyUp(VK_SPACE)) {
        space = false;
        state = IDLE;
        animAtck->Restart();
    }
    else if (window->KeyDown(VK_SPACE)) {
        space = true;

        if(state == IDLE )
            state = ATCK1;
        
        if (state == ATCK1 && animAtck->Inactive()){
            state = ATCK2;
            animAtck->Restart();
        }
        animAtck->Select(state);
        animAtck->NextFrame();
    }

    //------------------------------------------------------
    //enquanto está parado roda a animação
    if (state == IDLE) {
        animIdle->Select(state);
        animIdle->NextFrame();
    }
}

// ---------------------------------------------------------------------------------

void Player::Draw()
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

    case ATCK1 :
        animAtck->Draw(x, y, z, 1.5f);
        break;

    case ATCK2:
        animAtck->Draw(x, y, z, 1.5f);
        break;
       }

}

// ---------------------------------------------------------------------------------