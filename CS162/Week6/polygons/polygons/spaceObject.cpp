/** ---------------------------
* @file		Space Object.cpp
* @author	Masaki Nishi
* @version	1.3
*
* CS162 - Assignment 3.2 - Pointers and Dynamic Memory Allocation #2
*	Implements the SpaceObject class and its methods.
*
* --------------------------- */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "spaceObject.h"
#include "constants.h"

// Constructors

// --------------------------- 
SpaceObject::SpaceObject() {
	this->type = SpaceObjType::ASTEROID;
	this->radius = 20;
	this->location = { 0, 0 };
	this->velocity = { 0, 0 };
	this->angleDeg = 0;
};

// --------------------------- 
SpaceObject::SpaceObject(SpaceObjType type, double radius, Point location, Point velocity, double angle) {
	this->type = type;
	this->radius = 20;
	this->location = { 0, 0 };
	this->velocity = { 0, 0 };
	this->angleDeg = 0;

	this->setRadius(radius);
	this->setLocation(location.x, location.y);
	this->setVelocity(velocity.x, velocity.y);
	this->setAngle(angle);
};

// Mutators

// --------------------------- 
bool SpaceObject::setRadius(int radius) {
	if (radius > 0 && radius < (SCREEN_HEIGHT / 2)) {
		this->radius = radius;
		return true;
	}
	else {
		return false;
	}
}

// --------------------------- 
bool SpaceObject::setLocation(double x, double y) {
	while (x < 0) {
		x = x + SCREEN_WIDTH;
	}

	while (x > SCREEN_WIDTH) {
		x = x - SCREEN_WIDTH;
	}

	this->location.x = x;

	while (y < 0) {
		y = y + SCREEN_HEIGHT;
	}

	while (y > SCREEN_HEIGHT) {
		y = y - SCREEN_HEIGHT;
	}

	this->location.y = y;

	return true;
}

// --------------------------- 
bool SpaceObject::setVelocity(double velocityX, double velocityY) {
	this->velocity.x = velocityX;
	this->velocity.y = velocityY;

	return true;
}

// --------------------------- 
bool SpaceObject::setAngle(double angDeg) {
	this->angleDeg = angDeg;
	return true;
}

// --------------------------- 
void SpaceObject::changeAngle(double deltaDeg) {
	if (this->type == SpaceObjType::SHIP)
		this->setAngle(this->angleDeg + deltaDeg);
}

// Accessors

SpaceObjType SpaceObject::getType() const {
	return this->type;
}

// --------------------------- 
double SpaceObject::getRadius() const {
	return this->radius;
}

// --------------------------- 
Point SpaceObject::getLocation() const {
	return this->location;
}

// --------------------------- 
Point SpaceObject::getVelocity() const {
	return this->velocity;
}

// --------------------------- 
double SpaceObject::getAngle() const {
	return this->angleDeg;
}

// --------------------------- 
int SpaceObject::getTimesDrawn() const {
	return this->timesDrawn;
}

// - Others

// --------------------------- 
void SpaceObject::updatePosition() {
	this->setLocation((this->velocity.x + this->location.x), (this->velocity.y + this->location.y));
}

// --------------------------- 
void SpaceObject::draw(sf::RenderWindow& win) {
	if (this->type == SpaceObjType::SHIP)
		drawShip(win);
	else if (this->type == SpaceObjType::SHIP_EXPLODING)
		drawExplodingShip(win);
	else if (this->type == SpaceObjType::ASTEROID)
		drawAsteroid(win);
	else if (this->type == SpaceObjType::PHOTON_TORPEDO)
		drawAsteroid(win);

	this->timesDrawn++;
}

// --------------------------- 
void SpaceObject::drawAsteroid(sf::RenderWindow& win) {
	//Configure a graphics object to be used for drawing our object
	//this code draws a simple pentagon.Feel free to modify it if you want.
	int points = 5;
	sf::CircleShape shape(radius, points); //radius from our SpaceObject

	sf::Vector2f midpoint(radius, radius);
	shape.setOrigin(midpoint);

	shape.setFillColor(sf::Color(0, 0, 0));
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(255, 255, 255));

	//apply our object position to the graphics object and draw it
	shape.setPosition(location.x, location.y);
	shape.setRotation(angleDeg);

	win.draw(shape);

	//Note: if asteroid is near the edge (within a radius) then we should 
	//draw it again on the other side of the screen so the part off the edge 
	//shows up immediately on the other edge. Code to do that should be added
	//here.
}

// --------------------------- 
void SpaceObject::drawShip(sf::RenderWindow& win) {
	// draw ship
	sf::ConvexShape shipShape;
	shipShape.setPointCount(3);
	shipShape.setPoint(0, sf::Vector2f(10, 0));
	shipShape.setPoint(1, sf::Vector2f(0, 25));
	shipShape.setPoint(2, sf::Vector2f(20, 25));

	sf::Vector2f midpoint(10, 15);
	shipShape.setOrigin(midpoint);

	shipShape.setFillColor(sf::Color(0, 0, 0));
	shipShape.setOutlineThickness(1);
	shipShape.setOutlineColor(sf::Color(255, 255, 255));

	shipShape.setPosition(location.x, location.y);
	shipShape.setRotation(angleDeg);
	win.draw(shipShape);
}

// --------------------------- 
void SpaceObject::applyThrust(double engineThrust) {
	double forceX = cos((angleDeg - 90) * PI / 180) * engineThrust;
	double forceY = sin((angleDeg - 90) * PI / 180) * engineThrust;
	velocity.x = velocity.x + forceX;
	velocity.y = velocity.y + forceY;
}

// --------------------------- 
void SpaceObject::explode() {
	if (this->type == SpaceObjType::SHIP) {
		this->type = SpaceObjType::SHIP_EXPLODING;
		this->setVelocity(0, 0);
	}
}

// --------------------------- 
void SpaceObject::drawExplodingShip(sf::RenderWindow& win) {
	if (this->type != SpaceObjType::SHIP_GONE) {
		// draw circle
		sf::CircleShape shape(this->radius, 64); //radius from our SpaceObject

		sf::Vector2f midpoint(this->radius, this->radius);
		shape.setOrigin(midpoint);

		shape.setFillColor(sf::Color(0, 0, 0));
		shape.setOutlineThickness(1);
		shape.setOutlineColor(sf::Color(255, 255, 255));

		shape.setPosition(this->location.x, this->location.y);
		shape.setRotation(this->angleDeg);

		win.draw(shape);

		// Expand the circle for an animation of explosion
		setRadius(this->radius + 1.5);

		if (this->radius > 120)
			this->type = SpaceObjType::SHIP_GONE;
	}
};

// --------------------------- 
bool SpaceObject::isInCenter() const {
	// Sets the center lcation
	Point centerLocation = Point{ WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0 };
	double centerRadius = 100;

	// Calculates the total distance
	double xDistance = abs(location.x - centerLocation.x);
	double yDistance = abs(location.y - centerLocation.y);

	double totalDistance = sqrt((xDistance * xDistance) + (yDistance * yDistance));

	// Calculates the sum of the radius
	double radiiSum = centerRadius + radius;

	return radiiSum > totalDistance;
}

// --------------------------- 
Point Point::reverse() {
	return Point{
		this->x *= -1,
		this->y *= -1
	};
}