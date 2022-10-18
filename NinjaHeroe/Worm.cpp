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
#include <sstream>
using namespace std;

// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------

Worm::Worm(float x, float y)
{
    type = WORM;

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

    uint atck[16] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
    uint hit[3] = { 2,1,0};
    animAtck->Add(ATCK1, atck, 16);
    animTakeH->Add(TAKEHIT, hit, 3);

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
    stringstream ss;
    if (obj->Type() == PLAYER) {
        state = TAKEHIT;
        life -= 110;
        
        

    }
}

// ---------------------------------------------------------------------------------

void Worm::Update()
{
    if (state == IDLE)
        animIdle->NextFrame();
    
    if (state == ATCK1) {
        animAtck->Select(state);
        if(animAtck->Frame() == 5){
        fireball->MoveTo(X() - 55, Y() - 10, Layer::FRONT);
        fireball->shootOn();
        animAtck->NextFrame();
        }
        else {
            animAtck->NextFrame();
        }
    }
    
    if (animAtck->Inactive()){
        state = ATCK1;
        animAtck->Restart();
    }
    
    if (fireball->shoot){                                  // se a fireball estiver no estado de tiro, atualiza o frame da fireball
        fireball->shootOn();
        fireball->Update();
    }

   

}

// ---------------------------------------------------------------------------------
void Worm::Draw()
{
    switch (state)
    {


    case RUNING:
        animRun->Draw(x, y, z, 1.2f);
        break;

    case ATCK1:
        animAtck->Draw(x, y, z, 1.2f);
        break;
    case TAKEHIT:
        animTakeH->Draw(x, y, z, 1.2f);
        break;
    default:
        state = IDLE;
        animIdle->Draw(x, y, z, 1.2f);
        break;
    }
    fireball->Draw();
}