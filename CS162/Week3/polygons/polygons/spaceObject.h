#pragma once
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

struct Point {
	double x;
	double y;
};

enum SpaceObjType { SHIP, ASTEROID, PHOTON_TORPEDO };


class SpaceObject {

public:
	/**
	*	Initializes a SpaceObject with a type of ASTEROID, a radius of 20, a position of (0, 0), a velocity of (0, 0), and an angle of 0°
	*/
	SpaceObject();

	/**
	*	Initializes a SpaceObject
	*		@param type - the type of the object (defaults to ASTEROID if invalid)
	*		@param radius - the radius of the object (defaults to 20 if invalid)
	*		@param location - the location of the object (defaults to (0, 0) if invalid. If out of bounds, it's wrapped around the screen until it's back on screen)
	*		@param velocity - the velocity of the object (defaults to (0, 0) if invalid.)
	*		@param angle - the angle of the object (defaults to 0° if invalid.)
	*/
	SpaceObject(SpaceObjType type, double radius,
		Point location, Point velocity, double angle);

	//=============================================
	//mutators

	/**
	*	Sets the radius of a SpaceObject.
	*		@param radius - the character to be checked
	*		@return true if radius is valid,
	*				false otherwise (when negative and over half the screen height)
	*/
	bool setRadius(int radius);

	/**
	*	Sets the location of a SpaceObject.
	*		@param x - the x coordinate of the new position
	*		@param y - the y coordinate of the new position
	*		@return true upon completion
	*/
	bool setLocation(double x, double y);

	/**
	*	Sets the velocity of a SpaceObject. If the input is out of bounds, it's wrapped around the screen until it's back in bounds
	*		@param x - the x change (in pixels/frame) of the new velocity
	*		@param y - the y change (in pixels/frame) of the new velocity
	*		@return true upon completion
	*/
	bool setVelocity(double velocityX, double velocityY);

	/**
	*	Sets the angle of a SpaceObject.
	*		@param angDeg - the new angle (in degrees) of the SpaceObject
	*		@return true upon completion
	*/
	bool setAngle(double angDeg);

	/**
	*	Changes the angle of a SpaceObject by some delta
	*		@param deltaDeg - the number of degrees to change the angle of the SpaceObject by
	*/
	void changeAngle(double deltaDeg);

	//============================================
	//accessors

	/**
	*	Returns the radius of the SpaceObject
	*		@return the radius (double) of the SpaceObject
	*/
	double getRadius() const;

	/**
	*	Returns the location of the SpaceObject
	*		@return the position (Point) of the SpaceObject
	*/
	Point getLocation() const;

	/**
	*	Returns the velocity of the SpaceObject
	*		@return the velocity (Point) of the SpaceObject
	*/
	Point getVelocity() const;

	/**
	*	Returns the angle of the SpaceObject
	*		@return the angle (double) of the SpaceObject
	*/
	double getAngle() const;

	//============================================
	//others

	/**
	*	Updates the position of the SpaceObject based on its velocity.
	*/
	void updatePosition();

	void dumpData() const; //prints objects data to cout (for testing)

private:
	SpaceObjType type;	  //type of object
	Point location;	  //current location (x,y)
	Point velocity;	  //current velocity (in pixels/frame)
	double angleDeg;	  //angle object is facing (in degrees)
	double radius;        //gross radius of object (for collision detection)
};
