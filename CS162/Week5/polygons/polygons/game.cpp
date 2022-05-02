/** ---------------------------
* @file		game.cpp
* @author	Masaki Nishi
* @version	1.2
*
* CS162-01 - Assignment 3.1
*	 Implements a simple game loop
*
* --------------------------- */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "spaceObject.h"
#include "constants.h"

Point getRandomLocation();
Point getRandomVelocity();

bool objectsIntersect(SpaceObject* object1, SpaceObject* object2);

//============================================================================
int main()
{
	// A seed for the rand function
	srand(42);

	//create graphics window
	sf::RenderWindow window(
		sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Polygons!",
		sf::Style::Titlebar | sf::Style::Close
	);
	window.setFramerateLimit(60);

	//create SpaceObjects
	//create asteroid
	SpaceObject *asteroids[MAX_ASTEROIDS] = {0};
	for (int i = 0; i < 5; i++) {
		asteroids[i] = new SpaceObject(
			SpaceObjType::ASTEROID,
			60,
			getRandomLocation(),
			getRandomVelocity(),
			(rand() % 360)
		);
	}
	//create ship
	SpaceObject *ship = new SpaceObject(
		SpaceObjType::SHIP,
		20,
		{ 500.0, 500.0 },
		{ 0, 0 }, 
		45.0
	);

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
			ship->changeAngle(-2);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			ship->changeAngle(2);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			ship->applyThrust(0.04);


		// update game objects ------------------------------------------
		bool asteroidsInCenter = false;

		for (int i = 0; i < MAX_ASTEROIDS; i++) {
			// update position if asteroid is not null
			if (asteroids[i]) {
				asteroids[i]->updatePosition();
				// explode if the ship hits to the asteroids
				if (objectsIntersect(asteroids[i], ship) == true) {
					ship->explode();
				}
				// detects if the asteroids are in center
				if (asteroids[i]->isInCenter()) {
					asteroidsInCenter = true;
				}
			}
		}
		// recreates the ship if its gone when the asteroids are not in center
		if (!asteroidsInCenter && ship->getType() == SpaceObjType::SHIP_GONE) {
			// deletes the pointer to avoid a memory leak
			delete ship;
			ship = new SpaceObject(
				SpaceObjType::SHIP,
				20,
				{ 500.0, 500.0 },
				{ 0, 0 },
				45.0
			);
		}

		ship->updatePosition();

		// draw new frame ------------------------------------------------
		window.clear();
		for (int i = 0; i < MAX_ASTEROIDS; i++) {
			// draw to window if asteroid is not null
			if (asteroids[i]) {
				asteroids[i]->draw(window);
			}
		}
		ship->draw(window);
		window.display();
	}

	return 0;
}

/**
*	Gets a random location between 0 and the WINDOW_SIZE
*		@return Point location x and y
*/
Point getRandomLocation() {
	double x = rand() % WINDOW_WIDTH;
	double y = rand() % WINDOW_HEIGHT;

	// if the random location is between 400 and 600, add or subtract 250
	// to avoid the asteroids appear in the center of the window
	if (((WINDOW_WIDTH / 2.0) + 100) > x && ((WINDOW_WIDTH / 2.0) - 100) < x) {
		if (rand() % 2) {
			x += 250;
		}
		else {
			x -= 250;
		}
	}

	// for Y
	if (((WINDOW_WIDTH / 2.0) + 100) > y && ((WINDOW_WIDTH / 2.0) - 100) < y) {
		if (rand() % 2) {
			y += 250;
		}
		else {
			y -= 250;
		}
	}

	return Point{ x, y };
}

/**
*	Gets a random velocity between the low and the high
*		@return Point velocity x and y
*/
Point getRandomVelocity() {
	double low = -1.0;
	double high = 1.0;

	int range = (high - low + .001) * 1000;
	double x = (rand() % range) / 1000 + low;
	double y = (rand() % range) / 1000 + low;
	return Point{ x, y };
}

/**
*	Gets if two SpaceObjects overwrapped
*		@param object1 - the first object to be checked
*		@param object2 - the second object to be checked
*		@return true if the objects overwrapped, false otherwise
*/
bool objectsIntersect(SpaceObject* object1, SpaceObject* object2) {
	// Gets location and calculates total distance
	Point firstPosition = object1->getLocation();
	Point secondPosition = object2->getLocation();

	double xDistance = abs(firstPosition.x - secondPosition.x);
	double yDistance = abs(firstPosition.y - secondPosition.y);

	double totalDistance = sqrt((xDistance * xDistance) + (yDistance * yDistance));

	// Gets radius and calculates total radius
	double firstRadius = object1->getRadius();
	double secondRadius = object2->getRadius();

	double radiiSum = firstRadius + secondRadius;
	
	// Return true if the sum of radius is larger than total distance which objects are intersected
	return radiiSum > totalDistance;
}
