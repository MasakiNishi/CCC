/** ---------------------------
* @file		Space Object Test.cpp
* @author	Masaki Nishi
* @version	1.2
*
* CS162 - Assignment 2.2 - SpaceObject Class
*	Implements the SpaceObject class and its methods.
*
* --------------------------- */

#include "spaceObject.h"
#include <iostream>

using namespace std;

int main() {
	// test every method
	SpaceObject asteroid;
	asteroid.dumpData();

	Point location = { 100.0, 200.0 };
	Point velocity = { 300.0, 400.0 };
	SpaceObject ship(SpaceObjType::SHIP, 2.0, location, velocity, 30.0);
	ship.dumpData();

	ship.setRadius(40.0);
	ship.dumpData();

	ship.setLocation(200.0, 400.0);
	ship.dumpData();

	ship.setVelocity(100.0, 200.0);
	ship.dumpData();

	ship.setAngle(60.0);
	ship.dumpData();

	ship.changeAngle(20.0);
	ship.dumpData();

	std::cout << "---------------------------------------------" << std::endl;
	cout << ship.getRadius() << endl;
	cout << ship.getLocation().x << ", " << ship.getLocation().y << endl;
	cout << ship.getVelocity().x << ", " << ship.getVelocity().y << endl;
	cout << ship.getAngle() << endl;

	ship.updatePosition();
	ship.dumpData();
}