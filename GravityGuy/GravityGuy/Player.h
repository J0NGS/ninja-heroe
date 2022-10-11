/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _NINJAHEROE_PLAYER_H_
#define _NINJAHEROE_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum STATE { RUNING, IDLE, ATCK, TAKEHIT, DEATH, JUMPING, FALLING};         // tipo da gravidade

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet* tilesetJump;               // folha de sprites do personagem
    TileSet* tilesetRun;                // folha de sprites do personagem
    TileSet* tilesetIdle;               // folha de sprites do personagem
    TileSet* tilesetAtck;               // folha de sprites do personagem
    TileSet* tilesetDeath;              // folha de sprites do personagem
    TileSet* tilesetFall;               // folha de sprites do personagem
    TileSet* tilesetTake;               // folha de sprites do personagem
    
    Animation* anim;                    // anima��o do personagem
    
    uint        state;                  // estado do jogador
    int         level;                  // n�vel finalizado

public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // �ltimo n�vel finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline int Player::Level()
{
    return level;
}

inline float Player::Bottom()
{
    return y + tilesetIdle->Height() / 2;
}

inline float Player::Top()
{
    return y - tilesetIdle->Height() / 2;
}


// ---------------------------------------------------------------------------------

#endif