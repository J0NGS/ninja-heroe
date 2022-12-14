/**********************************************************************************
// Fireball (C?digo Fonte)
//
// Cria??o:     20 Abr 2012
// Atualiza??o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Fireball.h"
#include "NinjaHeroe.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Fireball::Fireball()
{
    //inicializando tileset e anima??o
    tileset = new TileSet("Resources/Worm/FireBall/Move.png", 46, 46, 6, 6);
    anim = new Animation(tileset, 0.120f, true);

    uint move[6] = { 5,4,3,2,1,0 };

    anim->Add(1, move, 6);
    // cria a bound box
    //inicializa o estado da bola
    shoot = false;
    damage = 50;
    //inicializando tipo do objeto
    type = FIREBALL;
    //inicializando velocidade
    speed = -60;
    BBox(new Circle(10));
}

// ---------------------------------------------------------------------------------

Fireball::~Fireball()
{
    delete anim;
    delete tileset;
}

// ---------------------Fun??es para ativar e desativar o tiro----------------------



void Fireball::shootOn()
{
    shoot = true;
}


void Fireball::shootOff()
{
    shoot = false;
}
// ---------------------------------------------------------------------------------

void Fireball::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER) {
        shootOff();
    }
}


void Fireball::Update()
{
    
    if (shoot) {
        Translate(speed * gameTime, 0);
        anim->Select(1);
        anim->NextFrame();
    }
}


void Fireball::Draw()
{
    if(shoot)
        anim->Draw(x, y, z, 1.5f);
}

// ---------------------------------------------------------------------------------