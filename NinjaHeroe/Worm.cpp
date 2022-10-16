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

#include "Worm.h"
#include "NinjaHeroe.h"

// ---------------------------------------------------------------------------------

Worm::Worm()
{
    // ------------------------Tileset&Animation------------------------------------
    tilesetRun = new TileSet("Resources/Worm/Worm/Walk.png", 90, 90, 9, 9);
    animRun = new Animation(tilesetRun, 0.120f, true);

    tilesetAtck = new TileSet("Resources/Worm/Worm/Attack.png", 90, 90, 16, 16);
    animAtck = new Animation(tilesetAtck, 0.120f, false);

    tilesetTakeH = new TileSet("Resources/Worm/Worm/GetHit.png", 90, 90, 3, 3);
    animTakeH = new Animation(tilesetTakeH, 0.120f, true);

    tilesetDeath = new TileSet("Resources/Worm/Worm/Death.png", 90, 90, 8, 8);
    animDeath = new Animation(tilesetDeath, 0.120f, true);

    tilesetIdle = new TileSet("Resources/Worm/Worm/Idle.png", 90, 90, 9, 9);
    animIdle = new Animation(tilesetIdle, 0.100f, true);
    // ---------------------------------------------------------------------------------
    //incializando state
    state = IDLE;
    //inicialização da fireball do inimigo]
    fireball = nullptr;
}
// ---------------------------------------------------------------------------------

Worm::Worm(float x, float y)
{
    // ------------------------Tileset&Animation------------------------------------
    tilesetRun = new TileSet("Resources/Worm/Worm/Walk.png", 90, 90, 9, 9);
    animRun = new Animation(tilesetRun, 0.120f, true);

    tilesetAtck = new TileSet("Resources/Worm/Worm/Attack.png", 90, 90, 16, 16);
    animAtck = new Animation(tilesetAtck, 0.120f, false);

    tilesetTakeH = new TileSet("Resources/Worm/Worm/GetHit.png", 90, 90, 3, 3);
    animTakeH = new Animation(tilesetTakeH, 0.120f, true);

    tilesetDeath = new TileSet("Resources/Worm/Worm/Death.png", 90, 90, 8, 8);
    animDeath = new Animation(tilesetDeath, 0.120f, true);

    tilesetIdle = new TileSet("Resources/Worm/Worm/Idle.png", 90, 90, 9, 9);
    animIdle = new Animation(tilesetIdle, 0.120f, true);
    // ---------------------------------------------------------------------------------
    //incializando state
    state = IDLE;
    //Posição inicial
    MoveTo(x, y);

    fireball = new Fireball();
    fireball->MoveTo(X() + 55, Y() - 10);


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
        if(animAtck->Frame() == 12){
        fireball->shootOn();
        animAtck->NextFrame();
        }
        else {
            animAtck->NextFrame();
        }
        if (animAtck->Inactive())
            state = IDLE;
    }
    if (fireball->shoot) {
        fireball->shootOn();
        fireball->Update();
    }


    if (space && window->KeyUp(VK_SPACE)) {
        space = false;
        state = IDLE;
        animAtck->Restart();
    }
    else if (window->KeyDown(VK_SPACE)) {
        space = true;

        if (state == IDLE)
            state = ATCK1;
        animAtck->Select(state);
        animAtck->NextFrame();
    }
}

// ---------------------------------------------------------------------------------
void Worm::Draw()
{
    if (state == IDLE) {
        fireball->Draw();
        animIdle->Draw(x, y, z, 1.5f);
    }
    if (state == RUNING){
        fireball->Draw();
        animRun->Draw(x, y, z, 1.5f);
    }
    if (state == DEATH){
        fireball->Draw();
        animDeath->Draw(x, y, z, 1.5f);
    }
    if (state == ATCK1){
        fireball->Draw();
        animAtck->Draw(x, y, z, 1.5f);
    }
    if (state == TAKEHIT){
        fireball->Draw();
        animTakeH->Draw(x, y, z, 1.5f);
    }
}