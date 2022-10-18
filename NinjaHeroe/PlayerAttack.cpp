#include "PlayerAttack.h"

PlayerAttack::PlayerAttack() {
	geom = new Circle(10); // 96 largura * 32 
	BBox(geom);
	type = PLAYERATTACK;
}

PlayerAttack::~PlayerAttack() {
}

void PlayerAttack::OnCollision(Object* obj) {
}

void PlayerAttack::Init() {
}

void PlayerAttack::Update() {
}

void PlayerAttack::Draw() {
	//sprite->Draw(x, y, Layer::BACK);
}

void PlayerAttack::Finalize() {
	delete geom;
}