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
        /**
        * Metoda zwracajaca wektor wskaznikow na kola pojazdu
        */
	std::vector<PPhysWheel> getWheels() const;
        /**
        * Metoda zwracajaca wskaznik na nadwozie pojazdu
        */
	PhysBodyShape* getBodyShape() const;
        /**
        * Metoda zwracajaca wektor zloczen kol z nadwoziem
        */
        std::vector<b2RevoluteJoint*> getJoints();
        /**
        * Metoda ustawiajaca wskaznik nadwozia
        */
	void setBodyShape(PPhysBodyShape body);
        /**
        * Metoda ustawiajaca wektor wskaznikow na kola
        */
	void setWheels(std::vector<PPhysWheel> wheels);
	/**
	* Metoda tworzaca polaczenie kola z nadwoziem
	*/
	void createJoint(b2World* world, PPhysWheel wheel);
	/**
	* Metoda wszystkie polaczenia kol z nadwoziem
	* @param - symulowany swiat fizyczny
	*/
	void createJoints(b2World* world);
	/**
	* Metoda uaktualniajaca predkosc kol pojazdu
	*/
        void updateVelocity(const float& value);
};

#endif
