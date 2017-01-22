#ifndef PHYSWHEEL_H 
#define PHYSWHEEL_H

#include <Box2D/Box2D.h>
#include <boost/make_shared.hpp>
#include "CarConst.h"
#include "PhysElement.h"
#include "ShapePoint.h"


/**
* \class PhysWheel
* Klasa odpowiadajaca kolu pojazdu
*
*/
class PhysWheel;
typedef boost::shared_ptr <PhysWheel> PPhysWheel;

class PhysWheel : public PhysElement
{
	/**
	* Promien kola
	*/
	float radius_;
	/**
	* Punkt doloaczenia kola do pojazdu
	*/
	ShapePoint jointPoint_;

public:
	PhysWheel();
	~PhysWheel();
        /**
        * Metoda zwracajaca promien
        */
	float getRadius() const;
        /**
        * Metoda zwracajaca punkt dolaczenia kola do nadwozia
        */
        ShapePoint getJointPoint() const;
        /**
        * Metoda ustawiajaca promien
        */
        void setRadius(const float& radius);
        /**
        * Metoda ustawiajaca punkt dolaczenia kola do nadwozia
        */
	void setJointPoint(ShapePoint point);
	/**
	* Metoda uaktulniajaca predkosc katowa kol, dbanie o ich stala predkosc
	*/
        void updateVelocity(const float& value);
	/**
	* Metoda tworzaca kolo w silniku fizycznym
	* @param world - symulaowany swiat fizyczny
	*/
	void createWheel(b2World& world);
};


#endif
