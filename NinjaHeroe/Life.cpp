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

#include "Life.h"
#include "NinjaHeroe.h"

// ---------------------------------------------------------------------------------

Life::Life(float x, float y)
{
    tileset = new TileSet("Resourcecs/Life/Life.png", 12, 10, 2 , 2);
    anim = new Animation(tileset, 0.120f, false);
    
    uint full[1] = { 1 };
    uint half[1] = { 2 };

    anim->Add(1, full, 1);
    anim->Add(2, half, 2);

    life = 100;

    MoveTo(x, y);
}


// ---------------------------------------------------------------------------------

Life::~Life()
{
    delete anim;
    delete tileset;
 }

// ---------------------------------------------------------------------------------

void Life::Damage(int dmg)
{
    life = life - dmg;
}


// ---------------------------------------------------------------------------------

void Life::OnCollision(Object* obj)
{
}

// ---------------------------------------------------------------------------------

void Life::Update()
{
    if (life > 50) {
        anim->Select(1);
        anim->NextFrame();
    }
    if (life <= 50) {
        anim->Select(2);
        anim->NextFrame();
    }
}

// ---------------------------------------------------------------------------------
