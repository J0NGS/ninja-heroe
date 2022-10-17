/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#ifndef _FORT_OF_ILLUSION_H_
#define _FORT_OF_ILLUSION_H_

// ------------------------------------------------------------------------------
// Inclusões

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
    static Scene* scene;           // cena do nível

    void Init();                    // inicialização do nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nível
};

// -----------------------------------------------------------------------------

#endif