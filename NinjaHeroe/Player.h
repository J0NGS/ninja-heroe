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

#ifndef _PLAYER_H_
#define _PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "PlayerAttack.h"
#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Life.h"                       // classe de vida

// ------------------------------------------------------------------------------


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
    //-----------------------------animation---------------------------------------------//
    Animation* animRun;                 // animação do personagem correndo
    Animation* animJump;                // animação do personagem pulando
    Animation* animIdle;                // animação do personagem parado
    Animation* animAtck;                // animação do personagem atacando
    Animation* animDeath;               // animação do personagem morrendo
    Animation* animFall;                // animação do personagem caindo
    Animation* animTake;                // animação do personagem tomando um hit
    //---------------------------controls-----------------------------------------------//
    bool right;
    bool up;
    bool left;
    bool space;
    
    uint        damage;                 // dano causado pelo jogador
    int         level;                  // nível finalizado
    PlayerAttack * attack1;
    //PlayerAttack * attack2;;
    

public:
    uint        l;
    uint        speed;
    uint        state;                  // estado do jogador
    float velY;
    bool moving = false;
    Timer* jumpTimer;
    float posY, posX;

    bool jumping = false;

    Player();                           // construtor
    ~Player();                          // destrutor

    Life * life;                   // vida do jogador
    uint l;
    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object* obj);      // resolução da colisão
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