/**********************************************************************************
// Fireball (Código Fonte)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Fireball.h"
#include "NinjaHeroe.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Fireball::Fireball()
{
    //inicializando tileset e animação
    tileset = new TileSet("Resources/Worm/FireBall", 46, 46, 6, 6);
    anim = new Animation(tileset, 0.120f, true);

    //inicializando tipo do objeto
    type = FIREBALL;
}

// ---------------------------------------------------------------------------------

Fireball::~Fireball()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Fireball::OnCollision(Object* obj)
{
    
}

// ---------------------------------------------------------------------------------

void Fireball::Update()
{
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------