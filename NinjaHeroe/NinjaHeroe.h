/**********************************************************************************
// Ninja Heroe (Arquivo de Cabe�alho)
//
// Cria��o:     09 Out 2022
// Atualiza��o: 09 Out 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef _NINJAHEROE_H_
#define _NINJAHEROE_H_

// --------------------------------------------------------------------------------------------------------------------------

#include "Player.h"
#include "Game.h"
#include "Audio.h"
#include "Resources.h"


// -----------------------------------------------------------------------------------------------------------------------

enum Sounds { MENU, MUSIC, TRANSITION };
enum STATE { RUNING, RUNINGLEFT, IDLE, ATCK1, ATCK2, TAKEHIT, DEATH, JUMPING, FALLING, ATCK1LEFT, ATCK2LEFT};         // Estados do player
enum TYPE {FIREBALL, WORM, PLAYER, BRICK, FIREWARRIOR, PLAYERATTACK, BRICKVOID, B };                               // Tipo do objeto
// ------------------------------------------------------------------------------

class NinjaHeroe : public Game
{
private:
    static Game* level;            // n�vel atual do jogo

public:
    static Player* player;
    //static Audio* audio;           // sistema de �udio
    static bool viewBBox;          // estado da bounding box


    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
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