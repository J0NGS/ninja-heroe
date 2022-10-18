/**********************************************************************************
// Brick (Arquivo de Cabe�alho)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _PLAYER_ATTACK_H_
#define _PLAYER_ATTACK_H_

// ------------------------------------------------------------TNC-TNC-TNC-TNC-TNC-----------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites
// ---------------------------------------------------------------------------------

class PlayerAttack : public Object
{
private:
    Geometry* geom = nullptr;
public:
    PlayerAttack();                 // construtor
    ~PlayerAttack();                // destrutor

    void OnCollision(Object* obj);

    void Init();
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void Finalize();
};

// ---------------------------------------------------------------------------------

#endif