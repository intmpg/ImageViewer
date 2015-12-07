#include "Buttons.h"

const int MAX_X_ZOOM = 4;
const int RANGE_FROM_WINDOW_EDGES = 10;

Buttons::Buttons() 
	: count_of_pictures(), menu_index(0), scale(1)
{
	texture[0].loadFromFile("img/switchLeft.png");
	sprite[0].setTexture(texture[0]);
	sprite[0].setScale(1, 0.5);

	texture[1].loadFromFile("img/switchRight.png");
	sprite[1].setTexture(texture[1]);
	sprite[1].setScale(1, 0.5);

	texture[2].loadFromFile("img/incZoom-24572__180.png");
	sprite[2].setTexture(texture[2]);
	sprite[2].setTextureRect(sf::IntRect(0, 0, 90, 90));
	sprite[2].setScale(0.5, 0.5);

	sprite[3].setTexture(texture[2]);
	sprite[3].setTextureRect(sf::IntRect(0, 90, 90, 90));
	sprite[3].setScale(0.5, 0.5);
}

void Buttons::update(sf::Vector2u window)
{
	sprite[0].setPosition(window.x / 2 - sprite[0].getGlobalBounds().width, window.y - sprite[0].getGlobalBounds().height - RANGE_FROM_WINDOW_EDGES);
	sprite[1].setPosition((window.x / 2), window.y - sprite[1].getGlobalBounds().height - RANGE_FROM_WINDOW_EDGES);
	sprite[2].setPosition(window.x - sprite[0].getGlobalBounds().width - RANGE_FROM_WINDOW_EDGES, window.y / 2 - sprite[0].getGlobalBounds().height);
	sprite[3].setPosition(window.x - sprite[1].getGlobalBounds().width - RANGE_FROM_WINDOW_EDGES, window.y / 2);
}

void Buttons::switchLeft()
{
	scale = 1;
	if (menu_index - 1 >= 0)
		menu_index--;
	else 
		menu_index = count_of_pictures - 1;
}
void Buttons::switchRight()
{
	scale = 1;
	if (menu_index + 1 < count_of_pictures)
		menu_index++;
	else 
		menu_index = 0;
}
void Buttons::incZoom()
{
	if (scale <= MAX_X_ZOOM)
		++scale;
}
void Buttons::dcrZoom()
{
	if (scale > 1)
		--scale;
}