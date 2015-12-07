#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
const int BUTTONS = 4;

struct Buttons
{
	Buttons();

	void update(sf::Vector2u window);

	void switchLeft();
	void switchRight();
	void incZoom();
	void dcrZoom();

	sf::Texture texture[BUTTONS - 1];
	sf::Sprite sprite[BUTTONS];
	int count_of_pictures;
	int menu_index;
	float scale;
};
