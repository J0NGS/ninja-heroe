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
#include "Life.h"                       // classe de vida

// ------------------------------------------------------------------------------

enum PLAYER{PLAYER};

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    //---------------------------tileset--------------------------------------------------//
    TileSet* tilesetJump;               // folha de sprites do personagem pulando
    TileSet* tilesetRun;                // folha de sprites do personagem correndo
    TileSet* tilesetIdle;               // folha de sprites do personagem parado
    TileSet* tilesetAtck;               // folha de sprites do personagem atacando
    TileSet* tilesetDeath;              // folha de sprites do personagem morrendo
    TileSet* tilesetFall;               // folha de sprites do personagem caindo
    TileSet* tilesetTake;               // folha de sprites do personagem tomando um hit
    TileSet* tilesetLife;               // folha de sprites do personagem tomando um hit
    //-----------------------------animation---------------------------------------------//
    Animation* animRun;                 // anima��o do personagem correndo
    Animation* animJump;                // anima��o do personagem pulando
    Animation* animIdle;                // anima��o do personagem parado
    Animation* animAtck;                // anima��o do personagem atacando
    Animation* animDeath;               // anima��o do personagem morrendo
    Animation* animFall;                // anima��o do personagem caindo
    Animation* animTake;                // anima��o do personagem tomando um hit
    Animation* animLife;                // anima��o do personagem tomando um hit
    //---------------------------controls-----------------------------------------------//
    bool right;
    bool up;
    bool left;
    bool space;

    Life*        life;                  // vida do jogador
    uint        state;                  // estado do jogador
    int         level;                  // n�vel finalizado

public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // �ltimo n�vel finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object* obj);      // resolu��o da colis�o
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