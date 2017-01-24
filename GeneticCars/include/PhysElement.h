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
	b2Body* body_;
	/**
	* gestosc ciala
	*/
	float density_;
public:
	PhysElement();
	~PhysElement();
        /**
        * Metoda zwracajaca wskaznik na cialo w silniku fizycznym
        */
	b2Body* getBody();
        /**
        * Metoda zwracajaca gestosc ciala
        */
	float getDensity() const;
        /**
        * Metoda ustawiajaca wskaznik na cialo
        */
	void setBody(b2Body* body);
        /**
        * Metoda ustawiajaca gestosc
        */
        void setDensity(float const& density);

};

#endif
