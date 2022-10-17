/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo
//
**********************************************************************************/

#ifndef _FORT_OF_ILLUSION_H_
#define _FORT_OF_ILLUSION_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "FortOfIllusionBG.h"
#include "Worm.h"
#include "Fireball.h"
#include "FireWarrior.h"
#include "Life.h"

// ------------------------------------------------------------------------------

class FortOfIllusion : public Game
{
private:
    FortOfIllusionBG* backg = nullptr;   // pano de fundo animado
    static Worm* worm;
    static FireWarrior* Firewarrior;
    static Fireball* fireball;
public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif