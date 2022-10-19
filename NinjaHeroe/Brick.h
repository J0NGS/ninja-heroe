/**********************************************************************************
// Brick (Arquivo de Cabeçalho)
//
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _BRICK_H_
#define _BRICK_H_

// ------------------------------------------------------------TNC-TNC-TNC-TNC-TNC-----------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites
#include "NinjaHeroe.h"                     // background é composto por sprites
#include <List>
// ---------------------------------------------------------------------------------

class Brick : public Object
{
private:
    Sprite   * sprite = nullptr;
    Geometry * geom   = nullptr;
public:
    Brick(string filename, uint t);                 // construtor
    ~Brick();                // destrutor

    void OnCollision(Object* obj);

    void Init();
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void Finalize();
};

// ---------------------------------------------------------------------------------

#endif