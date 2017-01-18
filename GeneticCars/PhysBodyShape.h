#ifndef PHYSBODYSHAPE_H 
#define PHYSBODYSHAPE_H

#include <vector>
#include <memory>
#include <boost/smart_ptr/make_unique.hpp>
#include <Box2D/Box2D.h>
#include "ShapePoint.h"
#include "CarConst.h"
#include "PhysElement.h"
#include "ShapePoint.h"

extern const float SCALE;

/**
*\class PhysBodyShape
* Klasa odpowiadajaca nadwoziu pojazdu
*
*/

class PhysBodyShape : public PhysElement
{
	/**
	* tablica sprytnych wskaznikow na wierzcholki nadwozia
	*/
	std::unique_ptr<b2Vec2[]> vertices_;

public:
	PhysBodyShape();
	~PhysBodyShape();
	b2Vec2 * getVertices() const;
	/**
	* metoda kopiujaca wartosci z podanego wektora do wskaznikow w tablicy  vertices_
	*/
	void setVerticesFromShapePoints(std::vector<ShapePoint>);
	/**
	* metoda tworzaca nadwozie w silniku fizycznym
	*/
	void createBodyShape(b2World&);
};




#endif