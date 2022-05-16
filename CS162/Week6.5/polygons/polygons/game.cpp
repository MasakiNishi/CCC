/** ---------------------------
* @file		game.cpp
* @author	Masaki Nishi
* @version	1.3
*
* CS162-01 - Assignment 3.2
*	 Implements a simple game loop
*
* --------------------------- */

#include <iostream>
#include <chrono>
#include <string>
#include <SFML/Graphics.hpp>
#include "spaceObject.h"
#include "constants.h"

Point getRandomLocation();
Point getRandomVelocity();

bool objectsIntersect(SpaceObject* object1, SpaceObject* object2);

void deleteAsteroids(SpaceObject* asteroids[], int index);

void splitAsteroids(SpaceObject* asteroids[], int index, Point velosity);

void drawScore(sf::RenderWindow& win, int &score);

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
			ASTEROID_RADIUS,
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
	//create photons
	SpaceObject *photons[MAX_PHOTONS] = {0};

	//initialize score
	int score = 0;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			ship->applyThrust(0.04);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			int i = 0;

			// find the null pointer to create photons
			while (photons[i] != nullptr) {
				i++;
			}

			// make sure the photon number is less than max number and the ship is still working
			if (i < MAX_PHOTONS && ship->getType() == SpaceObjType::SHIP) {
				photons[i] = new SpaceObject(
					SpaceObjType::PHOTON_TORPEDO,
					2,
					ship->getLocation(),
					ship->getVelocity(),
					ship->getAngle()
				);
				photons[i]->applyThrust(5);
			}
		}



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

		for (int i = 0; i < MAX_PHOTONS; i++) {
			// update position if the photon is not null
			if (photons[i]) {
				// Check if the photon has reached its lifespan time, and delete it if so
				if (photons[i]->getTimesDrawn() >= PHOTON_LIFESPAN) {
					deleteAsteroids(photons, i);
				}
				else {
					photons[i]->updatePosition();
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

			// score -50 if the ship is gone
			score -= 50;
		}

		ship->updatePosition();
 
		// if the photons and the asteroids are intersecting, delete both and set them to null pointers.
		for (int i = 0; i < MAX_PHOTONS; i++) {
			for (int j = 0; j < MAX_ASTEROIDS; j++) {
				if (photons[i] && asteroids[j]) {
					if (objectsIntersect(photons[i], asteroids[j]) == true) {
						// deletes the photons and sets to null
						deleteAsteroids(photons, i);

						// generates the splitted asteroids
						Point velosity = getRandomVelocity();
						splitAsteroids(asteroids, j, velosity);
						splitAsteroids(asteroids, j, velosity.reverse());

						// deletes the asteroids and sets to null
						deleteAsteroids(asteroids, j);

						// score up when destroy the asteroids
						score += 10;
					}
				}
			}
		}

		// draw new frame ------------------------------------------------
		window.clear();
		for (int i = 0; i < MAX_ASTEROIDS; i++) {
			// draw to window if asteroid is not null
			if (asteroids[i]) {
				asteroids[i]->draw(window);
			}
		}
		for (int i = 0; i < MAX_PHOTONS; i++) {
			// draw to window if photon is not null
			if (photons[i]) {
				photons[i]->draw(window);
			}
		}
		ship->draw(window);
		drawScore(window, score);
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

/**
*   Delete asteroids and set to null points.
* 		@param asteroids - objects to delete
*		@param index - index of the object
*/
void deleteAsteroids(SpaceObject* asteroids[], int index) {
	// delete asteroids and set to null
	delete asteroids[index];
	asteroids[index] = nullptr;
}

/**
*   Split asteroids into two.
* 		@param asteroids - objects to split
*		@param index - index of the object
*		@param velosity - velosity of two asteroids
*/
void splitAsteroids(SpaceObject* asteroids[], int index, Point velosity) {
	if (ASTEROID_RADIUS / 4.0 < asteroids[index]->getRadius()) {
		int i = 0;

		while (asteroids[i] != nullptr) {
			i++;
		}
		
		if (i <= MAX_ASTEROIDS) {
			asteroids[i] = new SpaceObject(
				SpaceObjType::ASTEROID,
				asteroids[index]->getRadius() / 2,
				asteroids[index]->getLocation(),
				velosity,
				asteroids[index]->getAngle()
			);
		}
	}
}


/** --------------------------------------------------------------------------
*   Draws the score on the given window
*
* 	@param win - the window on which we’ll draw the ship
*	@param score - the number of the score to draw
---------------------------------------------------------------------------- */
void drawScore(sf::RenderWindow& win, int &score) {
	sf::Font font;
	if (!font.loadFromFile("../../arial.ttf"))
	{
		std::cout << "Error loading font !";
	}
	sf::Text text;
	text.setFont(font);
	char scoreBoard[12];
	sprintf_s(scoreBoard, "Score: %d", score);
	text.setString(scoreBoard);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(850.f, 900.f);

	win.draw(text);
};