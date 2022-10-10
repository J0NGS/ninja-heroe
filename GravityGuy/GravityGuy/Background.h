/**********************************************************************************
// Background (Arquivo de Cabe�alho)
// 
// Cria��o:     09 Out 2022
// Atualiza��o: 09 Out 2022
// Compilador:  Visual C++ 2022
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
    float xF, xB;                      // posi��o horizontal dos sprites
    Image* imgF;                       // imagem de fundo frontal
    Image * imgM;                      // imagem de fundo meio
    Image* imgB;                       // imagem de fundo traseira    
    Image * imgLights;                 // imagem das luzes    

    Sprite* bgB;                          // fundo est�tico camada BACK
    Sprite* bgM;                          // fundo est�tico camada MIDDLE
    Sprite* bgF;                          // fundo est�tico camada FRONT

    //Sprite * backgF1;                   // pano de fundo din�mico (frontal 1)
    //Sprite * backgF2;                   // pano de fundo din�mico (frontal 2)
    //Sprite * backgB1;                   // pano de fundo din�mico (traseiro 1)
    //Sprite * backgB2;                   // pano de fundo din�mico (traseiro 2)

    Color color;                        // cor do pano de fundo

public:
    Background(Color tint);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif