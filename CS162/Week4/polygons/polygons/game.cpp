/** ---------------------------
* @file		game.cpp
* @author	Masaki Nishi
* @version	1.0
*
* CS162-01 - Assignment 2.2
*	 Implements a simple game loop
*
* --------------------------- */

#include "spaceObject.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

//============================================================================
int main()
{
	//create graphics window
	sf::RenderWindow window(
		sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Polygons!",
		sf::Style::Titlebar | sf::Style::Close
	);
	window.setFramerateLimit(60);

	//create SpaceObjects
	//create asteroid
	Point asteroidLocation = { 100.0, 100.0 };
	Point asteroidVelocity = { 5.5, 10.0 };
	SpaceObject asteroid(SpaceObjType::ASTEROID, 20, asteroidLocation, asteroidVelocity, 0);
	//create ship
	Point shipLocation = { 300.0, 300.0 };
	Point shipVelocity = { 0, 0 };
	SpaceObject ship(SpaceObjType::SHIP, 20, shipLocation, shipVelocity, 45.0);

		//game loop
	while (window.isOpen())
	{
		//handle user input (events and keyboard keys being pressed) ----
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			ship.changeAngle(-2);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			ship.changeAngle(2);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			ship.applyThrust(0.04);


		// update game objects ------------------------------------------
		asteroid.updatePosition();
		ship.updatePosition();

		// draw new frame ------------------------------------------------
		window.clear();
		asteroid.draw(window);
		ship.draw(window);
		window.display();
	}

	return 0;
}

