#ifndef PHYSCAR_H 
#define PHYSCAR_H

#include <Box2D/Box2D.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "ShapePoint.h"
#include "PhysBodyShape.h"
#include "PhysWheel.h"
#include "CarConst.h"

class PhysCar;
typedef boost::shared_ptr <PhysCar> PPhysCar;

class PhysCar
{
	/**
	* Wektor sprytnych wskaznikow na kola pojazdu
	*/
	std::vector<PPhysWheel> wheels_;
	/**
	* Sprytny wskaznik na nadwozie
	*/
	PPhysBodyShape bodyShape_;
	/**
	* wektor wskaznikow na polaczenia kol z nadwoziem
	*/
	std::vector<b2RevoluteJoint*> joints_;
public:
	PhysCar();
	~PhysCar();
	std::vector<PPhysWheel> getWheels() const;
	PhysBodyShape * getBodyShape() const;
	void setBodyShape(PPhysBodyShape);
	void setWheels(std::vector<PPhysWheel>);
	void setParts(std::vector<PPhysWheel>, PPhysBodyShape);
	/**
	* Metoda tworzaca polaczenie kola z nadwoziem
	*/
	void createJoint(b2World&, PPhysWheel);
	/**
	* Metoda wszystkie polaczenia kol z nadwoziem
	*/
	void createJoints(b2World&);
	/**
	* Metoda uaktualniajaca predkosc kol pojazdu
	*/
	void updateVelocity();
};

#endif