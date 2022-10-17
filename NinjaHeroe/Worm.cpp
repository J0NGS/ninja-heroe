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
    state = ATCK1;
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
    //Posição inicial
    MoveTo(x, y);
    //bola de fogo
    fireball = new Fireball();
    //Bound Box
    BBox(new Rect(
        -1.0f * tilesetRun->TileWidth() / 3.0,
        -1.0f * tilesetRun->TileHeight() / 5.0,
        tilesetRun->TileWidth() / 4.0,
        tilesetRun->TileHeight() / 6.0));
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
        fireball->MoveTo(X() + 55, Y() - 10, Layer::FRONT);
        fireball->shootOn();
        animAtck->NextFrame();
        }
        else {
            animAtck->NextFrame();
        }
    }
    
    if (animAtck->Inactive())
        state = IDLE;
    
    if (fireball->shoot){                                  // se a fireball estiver no estado de tiro, atualiza o frame da fireball
        fireball->shootOn();
        fireball->Update();
    }

   

}

// ---------------------------------------------------------------------------------
void Worm::Draw()
{
    if (state == IDLE) {
        fireball->Draw();
        animIdle->Draw(x, y, z);
    }
    if (state == RUNING){
        fireball->Draw();
        animRun->Draw(x, y, z);
    }
    if (state == DEATH){
        fireball->Draw();
        animDeath->Draw(x, y, z);
    }
    if (state == ATCK1){
        fireball->Draw();
        animAtck->Draw(x, y, z);
    }
    if (state == TAKEHIT){
        fireball->Draw();
        animTakeH->Draw(x, y, z);
    }
}