#include "Brick.h"
#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Player.h"

Brick::Brick(string filename, uint t) {
	sprite	= new Sprite(filename);
	geom = new Rect(-(sprite->Width() / 2), -(sprite->Height()/2), sprite->Width() / 2 , sprite->Height() / 2); // 96 largura * 32 
	BBox(geom);
	type = t;
	
}         

Brick::~Brick() {
}				

void Brick::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		if (((Player*)(obj))->Bottom() > sprite->Height() && type == BRICK) {
			((Player*)(obj))->MoveTo(((Player*)(obj))->X(), geom->Top() - 25);
		}

	}
}

void Brick::Init() {
}

void Brick::Update() {
}

void Brick::Draw() {
	sprite->Draw(x, y, Layer::BACK);
}

void Brick::Finalize() {
	delete sprite;
	delete geom;
}