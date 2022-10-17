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
    tileset = new TileSet("Resources/Worm/FireBall/Move.png", 46, 46, 6, 6);
    anim = new Animation(tileset, 0.120f, true);

    // cria a bound box
    //inicializa o estado da bola
    shoot = false;
    //inicializando tipo do objeto
    type = FIREBALL;
    //inicializando velocidade
    speed = 60;
    BBox(new Circle(10));
}

// ---------------------------------------------------------------------------------

Fireball::~Fireball()
{
    delete anim;
    delete tileset;
}

// ---------------------Funções para ativar e desativar o tiro----------------------



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
}


void Fireball::Update()
{
    
    if (shoot) {
        Translate(speed * gameTime, 0);
        anim->NextFrame();
    }
}


void Fireball::Draw()
{
    if(shoot)
        anim->Draw(x, y, z, 1.5f);
}

// ---------------------------------------------------------------------------------