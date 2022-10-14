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

#include "Worm.h"
#include "NinjaHeroe.h"

// ---------------------------------------------------------------------------------

Worm::Worm()
{
    // ------------------------Tileset&Animation------------------------------------
    tilesetRun = new TileSet("Resources/Worm/Worm/Walk.png", 90, 90, 9, 9);
    animRun = new Animation(tilesetRun, 0.120f, true);

    tilesetAtck = new TileSet("Resources/Worm/Worm/Attack.png", 90, 90, 16, 16);
    animAtck = new Animation(tilesetAtck, 0.120f, true);

    tilesetTakeH = new TileSet("Resources/Worm/Worm/GetHit.png", 90, 90, 3, 3);
    animTakeH = new Animation(tilesetTakeH, 0.120f, true);

    tilesetDeath = new TileSet("Resources/Worm/Worm/Death.png", 90, 90, 8, 8);
    animDeath = new Animation(tilesetDeath, 0.120f, true);

    tilesetIdle = new TileSet("Resources/Worm/Worm/Idle.png", 90, 90, 9, 9);
    animIdle = new Animation(tilesetIdle, 0.100f, true);
    // ---------------------------------------------------------------------------------
    //incializando state
    state = IDLE;
    //inicializa��o da fireball do inimigo]
    fireball = nullptr;
}
// ---------------------------------------------------------------------------------

Worm::Worm(float x, float y)
{
    // ------------------------Tileset&Animation------------------------------------
    tilesetRun = new TileSet("Resources/Worm/Worm/Walk.png", 90, 90, 9, 9);
    animRun = new Animation(tilesetRun, 0.120f, true);

    tilesetAtck = new TileSet("Resources/Worm/Worm/Attack.png", 90, 90, 16, 16);
    animAtck = new Animation(tilesetAtck, 0.120f, true);

    tilesetTakeH = new TileSet("Resources/Worm/Worm/GetHit.png", 90, 90, 3, 3);
    animTakeH = new Animation(tilesetTakeH, 0.120f, true);

    tilesetDeath = new TileSet("Resources/Worm/Worm/Death.png", 90, 90, 8, 8);
    animDeath = new Animation(tilesetDeath, 0.120f, true);

    tilesetIdle = new TileSet("Resources/Worm/Worm/Idle.png", 90, 90, 9, 9);
    animIdle = new Animation(tilesetIdle, 0.120f, true);
    // ---------------------------------------------------------------------------------
    //incializando state
    state = ATCK1;
    //Posi��o inicial
    MoveTo(x, y);

    fireball = new Fireball();
    fireball->MoveTo(X() + 28, Y() - 10);


}
// ---------------------------------------------------------------------------------

Worm::~Worm()
{
    delete animRun;
    delete animAtck;
    delete animTakeH;
    delete animDeath;
    delete animIdle;
    delete tilesetRun;
    delete tilesetAtck;
    delete tilesetTakeH;
    delete tilesetDeath;
    delete tilesetIdle;
}

// ---------------------------------------------------------------------------------




void Worm::OnCollision(Object* obj)
{


}

// ---------------------------------------------------------------------------------

void Worm::Update()
{
    if (state == IDLE)
        animIdle->NextFrame();
    if (state == ATCK1) {
        fireball->shoot = true;
        fireball->Update();
        animAtck->NextFrame();
    }
}

// ---------------------------------------------------------------------------------
void Worm::Draw()
{
    if (state == IDLE)
        animIdle->Draw(x, y, z, 1.5f);
    if (state == RUNING)
        animRun->Draw(x, y, z, 1.5f);
    if (state == DEATH)
        animDeath->Draw(x, y, z, 1.5f);
    if (state == ATCK1){
        fireball->Draw();
        animAtck->Draw(x, y, z, 1.5f);
    }
    if (state == TAKEHIT)
        animTakeH->Draw(x, y, z, 1.5f);
}