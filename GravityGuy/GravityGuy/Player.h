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

#ifndef _GRAVITYGUY_PLAYER_H_
#define _GRAVITYGUY_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

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
    
    Animation * animFall;                // anima��o do personagem
    Animation * animJump;               // anima��o do personagem
    Animation * animIdle;               // anima��o do personagem
    Animation * animAtck1;              // anima��o do personagem
    Animation * animAtck2;              // anima��o do personagem
    Animation * animTH1;                // anima��o do personagem
    Animation * animTH2;                // anima��o do personagem
    Animation * animDeath;              // anima��o do personagem
    Animation * animRun;                // anima��o do personagem
    
    uint        state;                  // estado do personalgem
    
    int         level;                  // n�vel finalizado
    
    
public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // �ltimo n�vel finalizado


    void OnCollision(Object * obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline int Player::Level()
{ return level; }


inline void Player::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif