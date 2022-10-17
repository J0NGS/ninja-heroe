
#include "Brick.h"
#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Player.h"

Brick::Brick(string filename) {
	sprite	= new Sprite(filename);
	
}         

Brick::~Brick() {
}				

void Brick::OnCollision(Object* obj) {
}

void Brick::Init() {
	geom = new Rect(-(sprite->Width() / 2), -(sprite->Height()/2), sprite->Width() / 2 , sprite->Height() / 2); // 96 largura * 32 
	BBox(geom);
	type = BRICK;
}

void Brick::Update() {
}

void Brick::Draw() {
	sprite->Draw(x, y, z);
}

void Brick::Finalize() {
	delete sprite;
	delete geom;
}