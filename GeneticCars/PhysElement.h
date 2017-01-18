#ifndef PHYSELEMENT_H 
#define PHYSELEMENT_H

#include<Box2D/Box2D.h>
#include "CarConst.h"

/**
* \class PhysElement
* Klasa, po ktorej dziedzicza wszstkie elementy odwzorowane w silniku fizycznym
*
*/

class PhysElement
{
	/**
	* wskaznik na cialo elementu w silniku fizyczniym
	*/
	b2Body * body_;
	/**
	* gestosc ciala
	*/
	float density_;
public:
	PhysElement();
	~PhysElement();
	b2Body * getBody();
	float getDensity() const;
	void setBody(b2Body *);
	void setDensity(float);

};

#endif