/**********************************************************************************
// Ground
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
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
