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

Life::Life(uint l)
{
    life = 350;

    tileset = new TileSet("Resources/Personagem/Life/Life.png", 64, 16, 9 , 9);
    anim = new Animation(tileset, 0.120f, false);
    
    uint heart1[1] = { 0 };
    uint heart2[1] = { 1 };
    uint heart3[1] = { 2 };
    uint heart4[1] = { 3 };
    uint heart5[1] = { 4 };
    uint heart6[1] = { 5 };
    uint heart7[1] = { 6 };
    uint heart8[1] = { 7 };
    uint heart9[1] = { 8 };

    anim->Add(0, heart1, 1);
    anim->Add(1, heart2, 1);
    anim->Add(2, heart3, 1);
    anim->Add(3, heart4, 1);
    anim->Add(4, heart5, 1);
    anim->Add(5, heart6, 1);
    anim->Add(6, heart7, 1);
    anim->Add(7, heart8, 1);
    anim->Add(8, heart9, 1);

    LifeCtrl = 0;
    MoveTo(window->CenterX() - window->CenterX() + 55 ,  40 + Y());
}


// ---------------------------------------------------------------------------------

Life::~Life()
{
    delete anim;
    delete tileset;
 }

// ---------------------------------------------------------------------------------

void Life::Damage(uint dmg)
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
    if (life = 400) {
        LifeCtrl = 1;
    } else if (life = 350){
        LifeCtrl = 1;
    }
    anim->Select(LifeCtrl);
}

// ---------------------------------------------------------------------------------
