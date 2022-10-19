/**********************************************************************************
// Worm (Arquivo de Cabeçalho)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _NINJAHEROE_WORM_H_
#define _NINJAHEROE_WORM_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
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
    
    Animation* animRun;                 // animação do personagem
    Animation* animDeath;               // animação do personagem
    Animation* animAtck;                // animação do personagem
    Animation* animTakeH;               // animação do personagem
    Animation* animIdle;                // animação do personagem
            
public:
    
    Worm();                             // construtor
    Worm(float x, float y);             // construtor
    ~Worm();                            // destrutor
    
    uint life;
    uint damage;
    Fireball* fireball;                 //
    uint      state;                    // Estado da minhoca

    int State();
    
    void OnCollision(Object* obj);      // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
inline int Worm::State()
{
    return state;
}
#endif