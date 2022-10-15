/**********************************************************************************
// Background (Arquivo de Cabe�alho)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _GROUND_H_
#define _GROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites
#include <List>
// ---------------------------------------------------------------------------------

class Ground : public Object
{
private:
    Geometry* line;
public:
    Ground(Point* x, Point* y);                 // construtor
    ~Ground();                // destrutor

    void OnCollision(Object* obj);

    void Init();
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void Finalize();
};

// ---------------------------------------------------------------------------------

#endif