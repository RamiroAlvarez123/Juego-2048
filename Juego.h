#pragma once
#include "TiledMap.h"
#include "Structures.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Juego
{

private:
    b2World& _world;
    TiledMap* _tiledMap;

    sf::Sound _sound;
	sf::SoundBuffer _buffer;

    int _lifes = 4;
	sf::Texture _lifesTexture;
	sf::Sprite _lifesSprite;

	int _totalPoints = 0;
	sf::Font _font;
	sf::Text _pointsText;

    Structures* _structures;
    Player* _player;
    std::string _playerName = "";

	bool _reintentar = false;
	bool _showCredits = false;
    bool _juego = true;

	sf::RectangleShape* _deathScreen;
	int _deathScreenOpacity = 0;
	bool _isFrozen = false;
	bool _isFadingOut = false;
public:
    Juego(b2World& world);
    void update();
    void render(sf::RenderWindow& window);
    void generateMap();
    void generateStructures();
    void spawnPlayer();
    void reintentar();
    void respawn();
    bool getJuego();
    bool getReintentar();
    void close();
    void open();
    sf::Vector2f getCameraPosition();

};
