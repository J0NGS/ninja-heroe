/**********************************************************************************
// Background (Arquivo de Cabeçalho)
// 
// Criação:     09 Out 2022
// Atualização: 09 Out 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _NINJAHEROE_BACKGROUND_H_
#define _NINJAHEROE_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float xF, xB;                      // posição horizontal dos sprites
    Image* imgF;                       // imagem de fundo frontal
    Image * imgM;                      // imagem de fundo meio
    Image* imgB;                       // imagem de fundo traseira    
    Image * imgLights;                 // imagem das luzes    

    Sprite* bgB;                          // fundo estático camada BACK
    Sprite* bgM;                          // fundo estático camada MIDDLE
    Sprite* bgF;                          // fundo estático camada FRONT

    //Sprite * backgF1;                   // pano de fundo dinâmico (frontal 1)
    //Sprite * backgF2;                   // pano de fundo dinâmico (frontal 2)
    //Sprite * backgB1;                   // pano de fundo dinâmico (traseiro 1)
    //Sprite * backgB2;                   // pano de fundo dinâmico (traseiro 2)

    Color color;                        // cor do pano de fundo

public:
    Background(Color tint);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif