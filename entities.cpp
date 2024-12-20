#include "entities.h"

Entities::Entities(float width, float height, float moveSpeed)
    : _width(width), _height(height), _moveSpeed(moveSpeed),
      _velocity(0.0f, 0.0f){

}

Entities::~Entities() {

}

void Entities::render(sf::RenderWindow& window) {
	_sprite->setPosition(_body->GetPosition().x * pixels_per_meter, _body->GetPosition().y * pixels_per_meter);
	_sprite->setRotation(_body->GetAngle() * deg_per_rad);
	window.draw(*_sprite);
}

bool Entities::isDead() const {
    return _isDead;
}

