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

#ifndef _NINJAHEROE_FIREWARRIOR_H_
#define _NINJAHEROE_FIREWARRIOR_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum FIREWARRIOR { FIREWARRIOR };

// ---------------------------------------------------------------------------------

class FireWarrior: public Object
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
    Animation* animRun;                 // anima��o do personagem correndo
    Animation* animJump;                // anima��o do personagem pulando
    Animation* animIdle;                // anima��o do personagem parado
    Animation* animAtck;                // anima��o do personagem atacando
    Animation* animDeath;               // anima��o do personagem morrendo
    Animation* animFall;                // anima��o do personagem caindo
    Animation* animHit;                 // anima��o do personagem tomando um hit


    uint        damage;                 // dano do jogador
    uint        life;                   // vida do jogador
    uint        state;                  // estado do jogador
    int         level;                  // n�vel finalizado

public:
    FireWarrior();                           // construtor
    ~FireWarrior();                          // destrutor


    void OnCollision(Object* obj);      // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline




// ---------------------------------------------------------------------------------

#endif