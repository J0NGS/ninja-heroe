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

#include "Brick.h"
#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "FortOfIllusionBG.h"
#include "Worm.h"
#include "Fireball.h"
#include "FireWarrior.h"
#include "Life.h"
#include "Brick.h"

// ------------------------------------------------------------------------------

class FortOfIllusion : public Game
{
private:

    FortOfIllusionBG* backg = nullptr;   // pano de fundo animado
    float brickSpeed;
    static Worm* worm;
    static Worm* worm2;
    static Worm* worm3;
    static FireWarrior* Firewarrior;
    static Fireball* fireball;
    
    Brick* brickVoid = nullptr;
    Brick* brickVoid2 = nullptr;

    Brick* brick1 = nullptr;
    Brick* brick2 = nullptr;
    Brick* brick3 = nullptr;
    Brick* brick4 = nullptr;
    Brick* brick5 = nullptr;
    Brick* brick6 = nullptr;
    Brick* brick7 = nullptr;


public:
    static Scene* scene;           // cena do nível

    FortOfIllusion();
    ~FortOfIllusion();
    
    void Init();                    // inicialização do nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nível
};

// -----------------------------------------------------------------------------

#endif