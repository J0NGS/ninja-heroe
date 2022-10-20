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
		// se o jogador passar a bbox por cima ele é automaticamente movido para cima da bbox.
		if (((Player*)(obj))->Bottom() > sprite->Height() && type == BRICK && ((Player*)(obj))->state != FALLING) {
			((Player*)(obj))->MoveTo(((Player*)(obj))->X(), geom->Top() - 25);
		}
		// se o jogador passar a bbox pela direita ele é automaticamente movido para direta da bbox.
		if (((Player*)(obj))->Right() > (sprite->Width()/2) && type == BRICK) {
			((Player*)(obj))->MoveTo(((Player*)(obj))->X(), geom->Top() - 25);
		}
		
		/* se o jogador passar a bbox pela esquerda ele é automaticamente movido para esquerda da bbox.
		if (((Player*)(obj))->Bottom() > sprite->Height() && type == BRICK) {
			((Player*)(obj))->MoveTo(((Player*)(obj))->X(), geom->Top() - 25);
		}*/
		
		if (((Player*)(obj))->Bottom() > sprite->Height() && type == MINIBRICK) {
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