/**********************************************************************************
// Ninja Heroe (Arquivo de Cabeçalho)
//
// Criação:     09 Out 2022
// Atualização: 09 Out 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef _NINJAHEROE_H_
#define _NINJAHEROE_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Resources.h"
#include "Player.h"
#include "Worm.h"


// ------------------------------------------------------------------------------

enum Sounds { MENU, MUSIC, TRANSITION };
enum STATE { RUNING, IDLE, ATCK1, ATCK2, TAKEHIT, DEATH, JUMPING, FALLING };         // Estados do player
                                                               // Tipo do objeto
// ------------------------------------------------------------------------------

class NinjaHeroe : public Game
{
private:
    static Game* level;            // nível atual do jogo

public:
    static Audio* audio;           // sistema de áudio
    static bool viewBBox;          // estado da bounding box
    static Player* player;


    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para próximo nível do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif