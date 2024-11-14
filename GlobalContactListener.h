#pragma once
#include <box2d/box2d.h>

class Player;
class Enemy;
class RedEnemy;
class Star;

class ContactListener {
public:
	virtual void onBeginContact(b2Fixture* self, b2Fixture* other) = 0;
	virtual void onEndContact(b2Fixture* self, b2Fixture* other) = 0;
};

enum class FixtureDataType {
	Player,
	GroundTile,
	Enemy,
	RedEnemy,
	Spike,
	Finish,
};

struct FixtureData {
	FixtureDataType type;
	ContactListener* listener;

	union {
		Player* player;
		Enemy* enemy;
		RedEnemy* redenemy;
		Star* star;
	};
};

class GlobalContactListener : public b2ContactListener
{
public:
	virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;
};
