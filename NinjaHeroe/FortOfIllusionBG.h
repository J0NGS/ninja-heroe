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
#include <List>
// ---------------------------------------------------------------------------------

class FortOfIllusionBG : public Object
{
private:
    Image * mountainImg  = nullptr;        // imagem de fundo frontal
    Sprite* mountains[10] = {};
    Sprite* fortOfIllusion = nullptr;
    
    
public:
    FortOfIllusionBG();                 // construtor
    ~FortOfIllusionBG();                // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void Finalize();
};

// ---------------------------------------------------------------------------------

#endif