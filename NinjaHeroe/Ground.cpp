/**********************************************************************************
// Ground
//
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Player.h"
#include "Ground.h"



// ------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------


Ground::Ground(Point * x, Point * y) {
	line = new Line(*x, *y);
	BBox(line);
}

Ground::~Ground() {

}

void Ground::Init() {
}

void Ground::OnCollision(Object* obj) {
	((Player*) obj)->MoveTo(x, y);
}

void Ground::Update() {

}
void Ground::Draw() {
}
void Ground::Finalize() {

}
