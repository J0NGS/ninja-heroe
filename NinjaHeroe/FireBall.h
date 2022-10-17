#pragma once
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

#ifndef _NINJAHEROE_FIREBALL_H_
#define _NINJAHEROE_FIREBALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites


// ------------------------------------------------------------------------------
enum Type {FIREBALL};
// ------------------------------------------------------------------------------

class Fireball : public Object
{
private:
    TileSet* tileset;                // folha de sprites do personagem
    Animation* anim;                   // anima��o do personagem
    float speed;
public:
    Fireball();                           // construtor
    ~Fireball();                          // destrutor

    bool shoot;
    void shootOn();
    void shootOff();

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline


// ---------------------------------------------------------------------------------

#endif