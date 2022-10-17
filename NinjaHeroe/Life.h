/**********************************************************************************
// Life (Arquivo de Cabeçalho)
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _NINJAHEROE_LIFE_H_
#define _NINJAHEROE_LIFE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ---------------------------------------------------------------------------------

class Life : public Object
{
private:
    //---------------------------tileset--------------------------------------------------//
    TileSet* tileset;
    //-----------------------------animation---------------------------------------------//
    Animation* anim;                 // animação do personagem correndo
    //---------------------------controls-----------------------------------------------//
    
    uint        life;

public:
    Life(uint l);                    // construtor
    ~Life();                             // destrutor

    uint    LifeCtrl;  
    void Damage(uint dmg);                // volta ao estado inicial
    int LifeValue();                     // último nível finalizado
    
    void OnCollision(Object* obj);       // resolução da colisão
    void Update();                       // atualização do objeto
    void Draw();                         // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline int Life::LifeValue()
{
    return life;
}

inline void Life::Draw() {
    anim->Draw(x, y, z, 1.15);
}
// ---------------------------------------------------------------------------------

#endif