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

#ifndef _BRICK_H_
#define _BRICK_H_

// ------------------------------------------------------------TNC-TNC-TNC-TNC-TNC-----------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites
#include "NinjaHeroe.h"                     // background � composto por sprites
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
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void Finalize();
};

// ---------------------------------------------------------------------------------

#endif