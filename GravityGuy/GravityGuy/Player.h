/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _NINJAHEROE_PLAYER_H_
#define _NINJAHEROE_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

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
    
    Animation* anim;                    // animação do personagem
    
    uint        state;                  // estado do jogador
    int         level;                  // nível finalizado

public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

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