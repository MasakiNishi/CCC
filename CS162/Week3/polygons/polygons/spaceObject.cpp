/** ---------------------------
* @file		Space Object.cpp
* @author	Masaki Nishi
* @version	1.0
*
* CS162 - Assignment 2.1 - SpaceObject Class
*	Implements the SpaceObject class and its methods.
*
* --------------------------- */

#include "spaceObject.h"
#include <iostream>

// Constructors

// --------------------------- 
SpaceObject::SpaceObject() {
	type = ASTEROID;
	radius = 20;
	location = { 0, 0 };
	velocity = { 0, 0 };
	angleDeg = 0;
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
	this->setAngle(this->angleDeg + deltaDeg);
}

// Accessors

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

// - Others

// --------------------------- 
void SpaceObject::updatePosition() {
	this->setLocation((this->velocity.x + this->location.x), (this->velocity.y + this->location.y));
}

void SpaceObject::dumpData() const
{
	std::cout << "---------------------------------------------" << std::endl;
	if (this->type == SHIP) {
		std::cout << "type is SHIP" << std::endl;
	}
	else if (this->type == ASTEROID) {
		std::cout << "type is ASTEROID" << std::endl;
	}
	else {
		std::cout << "type is PHOTON_TORPEDO" << std::endl;
	}
	std::cout << "radius is " << this->radius << std::endl;
	std::cout << "location is x:" << this->location.x << " y:" << this->location.y << std::endl;
	std::cout << "velocity is x:" << this->velocity.x << " y:" << this->velocity.y << std::endl;
	std::cout << "angleDeg is " << this->angleDeg << std::endl;
}
