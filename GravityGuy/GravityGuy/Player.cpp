/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"
#include "NinjaHeroe.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tilesetRun = new TileSet("Resources/Personagem/Run.png", 200, 200, 8, 8);
    anim = new Animation(tilesetRun, 0.120f, true);

    //sequencia de anima��o
    uint run[8] = { 1,2,3,4,5,6,7,8 };
    
    // cria bounding box
    BBox(new Rect(
        -1.0f * tilesetRun->TileWidth() / 7.0f,
        -1.0f * tilesetRun->TileHeight() / 8.0f,
        tilesetRun->TileWidth() / 7.0f,
        tilesetRun->TileHeight() / 8.0f));

    // inicializa estado do player
    state = RUNING;
    level = 0;

    // posi��o inicial
    MoveTo(window->CenterX(),window->CenterY() + (window->CenterY()/2), Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tilesetRun;
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
    // atualiza anima��o
    anim->Select(state);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    if (state == RUNING)
        anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------