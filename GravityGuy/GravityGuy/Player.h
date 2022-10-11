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

#ifndef _GRAVITYGUY_PLAYER_H_
#define _GRAVITYGUY_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

enum STATE {RUNING, ATCK_1, ATCK_2, IDLE, FALLING, JUMPING, TAKE_HIT_1, TAKE_HIT_2, DEATH};

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tilesetRun;             // folha de sprites do personagem
    TileSet   * tilesetFall;            // folha de sprites do personagem
    TileSet   * tilesetAtck2;           // folha de sprites do personagem
    TileSet   * tilesetAtck1;           // folha de sprites do personagem
    TileSet   * tilesetJump;            // folha de sprites do personagem
    TileSet   * tilesetTakeHit1;        // folha de sprites do personagem
    TileSet   * tilesetTakeHit2;        // folha de sprites do personagem
    TileSet   * tilesetDeath;           // folha de sprites do personagem
    TileSet   * tilesetIdle;            // folha de sprites do personagem
    
    Animation * animFall;                // animação do personagem
    Animation * animJump;               // animação do personagem
    Animation * animIdle;               // animação do personagem
    Animation * animAtck1;              // animação do personagem
    Animation * animAtck2;              // animação do personagem
    Animation * animTH1;                // animação do personagem
    Animation * animTH2;                // animação do personagem
    Animation * animDeath;              // animação do personagem
    Animation * animRun;                // animação do personagem
    
    uint        state;                  // estado do personalgem
    
    int         level;                  // nível finalizado
    
    
public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado


    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline int Player::Level()
{ return level; }


inline void Player::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif