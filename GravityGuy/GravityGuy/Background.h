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
    float xF, xM, xB, xL;                       // posi��o horizontal dos sprites

    Image* imgF;                       // imagem de fundo frontal
    Image* imgM;                       // imagem de fundo MEIO
    Image* imgB;                       // imagem de fundo traseira
    Image* imgL;                       // imagem de fundo traseira

    Sprite* frontbg;
    Sprite* midlebg;
    Sprite* lowerbg;
    Sprite* backbg;

    bool moving = false;                        // Booleano para controlar movimento do bckg
    
    Color color;                       // cor do plano de fundo

public:
    Background(Color tint);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto

    void xFront(float xf);
    void xBack(float xB);
    void xMiddle(float xM);
    void xLower(float xL);
};

inline void Background::xFront(float xf) {
    xF -= xf;
}

inline void Background::xBack(float xb) {
    xB -= xb;
}

inline void Background::xMiddle(float xm) {
    xM -= xm;
}

inline void Background::xLower(float xl) {
    xL -= xl;
}

// ---------------------------------------------------------------------------------

#endif