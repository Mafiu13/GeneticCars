#ifndef PHYSELEMENT_H 
#define PHYSELEMENT_H

#include<Box2D/Box2D.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "CarConst.h"

/**
* \class PhysElement
* Klasa, po ktorej dziedzicza wszstkie elementy odwzorowane w silniku fizycznym
*
*/
class PhysElement;
typedef boost::shared_ptr <PhysElement> PPhysElement;

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
	void setBody(b2Body * body);
	void setDensity(float density);

};

#endif