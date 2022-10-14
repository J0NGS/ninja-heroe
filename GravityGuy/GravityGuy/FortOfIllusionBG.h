/**********************************************************************************
// Background (Arquivo de Cabeçalho)
//
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _FORT_OF_ILLUSION_BG_H_
#define _FORT_OF_ILLUSION_BG_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class FortOfIllusionBG : public Object
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
    FortOfIllusionBG(Color tint);             // construtor
    ~FortOfIllusionBG();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif