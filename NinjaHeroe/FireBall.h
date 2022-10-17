#pragma once
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

#ifndef _NINJAHEROE_FIREBALL_H_
#define _NINJAHEROE_FIREBALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites


// ------------------------------------------------------------------------------
enum Type {FIREBALL};
// ------------------------------------------------------------------------------

class Fireball : public Object
{
private:
    TileSet* tileset;                // folha de sprites do personagem
    Animation* anim;                   // animação do personagem
    float speed;
public:
    Fireball();                           // construtor
    ~Fireball();                          // destrutor

    bool shoot;
    void shootOn();
    void shootOff();

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline


// ---------------------------------------------------------------------------------

#endif