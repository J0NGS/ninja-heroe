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

#ifndef _NINJAHEROE_BACKGROUND_H_
#define _NINJAHEROE_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    Image* imgF;                       // imagem de fundo frontal
    Image* imgM;                       // imagem de fundo MEIO
    Image* imgB;                       // imagem de fundo traseira
    Image* imgL;                       // imagem de fundo traseira

    Sprite* frontbg;
    Sprite* midlebg;
    Sprite* lowerbg;
    Sprite* backbg;
    
    Color color;                       // cor do plano de fundo

public:
    Background(Color tint);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif