/**********************************************************************************
// Life (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _NINJAHEROE_LIFE_H_
#define _NINJAHEROE_LIFE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ---------------------------------------------------------------------------------

class Life : public Object
{
private:
    //---------------------------tileset--------------------------------------------------//
    TileSet* tileset;
    //-----------------------------animation---------------------------------------------//
    Animation* anim;                 // anima��o do personagem correndo
    //---------------------------controls-----------------------------------------------//
    
                                        // dano do jogador
    uint        life;                   // vida do jogador

public:
    Life(float x, float y);                             // construtor
    ~Life();                            // destrutor

    void Damage(int dmg);                       // volta ao estado inicial
    int LifeValue();                     // �ltimo n�vel finalizado
    
    void OnCollision(Object* obj);      // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline int Life::LifeValue()
{
    return life;
}

inline void Life::Draw() {
    anim->Draw(x, y, z);
}
// ---------------------------------------------------------------------------------

#endif