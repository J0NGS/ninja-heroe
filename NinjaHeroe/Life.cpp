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
    life = l;

    tileset = new TileSet("Resources/Personagem/Life/Life.png", 64, 16, 9 , 9);
    anim = new Animation(tileset, 0.120f, false);
    
    uint heart1[9] = { 0,1,2,3,4,5,6,7,8 };
    /*uint heart2[1] = {1};
    uint heart3[1] = { 2 };
    uint heart4[1] = { 3 };
    uint heart5[1] = { 4 };
    uint heart6[1] = { 5 };
    uint heart7[1] = { 6 };
    uint heart8[1] = { 7 };
    uint heart9[1] = { 8 };
    */
    anim->Add(1, heart1, 9);
    /*anim->Add(0, heart1, 1);
    anim->Add(2, heart3, 1);
    anim->Add(3, heart4, 1);
    anim->Add(4, heart5, 1);
    anim->Add(5, heart6, 1);
    anim->Add(6, heart7, 1);
    anim->Add(7, heart8, 1);
    anim->Add(8, heart9, 1);
    */
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
    life -= dmg;

}


// ---------------------------------------------------------------------------------

void Life::OnCollision(Object* obj)
{
}

// ---------------------------------------------------------------------------------

void Life::Update()
{

    if (life == 400) {
        anim->Frame(0);
    } 
    if (life >= 350 && life < 400){
        anim->Frame(1);
    }
    if (life >= 300 && life < 350) {
        anim->Frame(2);
    }if (life >= 250 && life < 300) {
        anim->Frame(3);
    }if (life >= 200 && life < 250) {
        anim->Frame(4);
    }
    if (life >= 150 && life < 200) {
        anim->Frame(5);
    }
    if (life >= 100 && life < 150) {
        anim->Frame(6);
    }
    if (life >= 50 && life < 100) {
        anim->Frame(7);
    }
    if (life > 0 && life < 50) {
        anim->Frame(8);
    }
    if (life == 0) {
        anim->Frame(9);
        anim->Restart();
    }


}

// ---------------------------------------------------------------------------------
