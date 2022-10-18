#include "Brick.h"
#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "Player.h"

Brick::Brick(string filename) {
	sprite	= new Sprite(filename);
	geom = new Rect(-(sprite->Width() / 2), -(sprite->Height()/2), sprite->Width() / 2 , sprite->Height() / 2); // 96 largura * 32 
	BBox(geom);
	type = BRICK;
}         

Brick::~Brick() {
}				

void Brick::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		OutputDebugStringA("BRICKVOID");
		OutputDebugStringA("\n");
		NinjaHeroe::player->speed = 750;
		NinjaHeroe::player->state = FALLING;
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