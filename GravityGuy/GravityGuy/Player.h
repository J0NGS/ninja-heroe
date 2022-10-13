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

enum STATE { RUNING, IDLE, ATCK1, ATCK2 ,TAKEHIT, DEATH, JUMPING, FALLING};         // Estados do player

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

    uint        state;                  // estado do jogador
    int         level;                  // nível finalizado

    bool moving;                        // booleano para controlar movimento
    bool jumping;                       // booleano para controlar pulo
    bool fall;                          // booleano para controlar queda
    
public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo
    bool Moving();
    bool Jmping();
    bool Fall();
    void OnCollision(Object* obj);      // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline bool Player::Moving() { return moving; }
inline bool Player::Jmping() { return jumping; }
inline bool Player::Fall() { return moving; }


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