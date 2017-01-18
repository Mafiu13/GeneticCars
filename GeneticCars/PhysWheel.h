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
	float getRadius() const;
	void setRadius(float);
	ShapePoint getJointPoint() const;
	void setJointPoint(ShapePoint);
	/**
	* Metoda uaktulniajaca predkosc katowa kol
	*/
	void updateVelocity();
	/**
	* Metoda tworzaca kolo w silniku fizycznym
	*/
	void createWheel(b2World &);
};


#endif