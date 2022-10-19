/**********************************************************************************
// Worm (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _NINJAHEROE_WORM_H_
#define _NINJAHEROE_WORM_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
//#include "Player.h"
#include "Fireball.h"



// ------------------------------------------------------------------------------

//enum State { ATCKWORM, DEATHWORM, TAKEHITWORM, IDLEWORM, RUNWORM };         // tipo da gravidade


// ---------------------------------------------------------------------------------

class Worm : public Object
{
private:
    TileSet* tilesetRun;                // folha de sprites do personagem
    TileSet* tilesetDeath;              // folha de sprites do personagem
    TileSet* tilesetAtck;               // folha de sprites do personagem
    TileSet* tilesetTakeH;              // folha de sprites do personagem
    TileSet* tilesetIdle;               // folha de sprites do personagem
    
    Animation* animRun;                 // anima��o do personagem
    Animation* animDeath;               // anima��o do personagem
    Animation* animAtck;                // anima��o do personagem
    Animation* animTakeH;               // anima��o do personagem
    Animation* animIdle;                // anima��o do personagem
            
public:
    
    Worm();                             // construtor
    Worm(float x, float y);             // construtor
    ~Worm();                            // destrutor
    
    uint life;
    uint damage;
    Fireball* fireball;                 //
    uint      state;                    // Estado da minhoca

    int State();
    
    void OnCollision(Object* obj);      // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
inline int Worm::State()
{
    return state;
}
#endif