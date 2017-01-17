#ifndef PHYSBODYSHAPE_H 
#define PHYSBODYSHAPE_H

#include <vector>
#include <memory>
#include <boost/smart_ptr/make_unique.hpp>
#include <Box2D/Box2D.h>
#include "ShapePoint.h"
#include "const.h"
#include "PhysElement.h"
#include "ShapePoint.h"

extern const float SCALE;

class PhysBodyShape : public PhysElement
{
	//tablica sprytnych wskaznikow do stworzenia nadwozia
	std::unique_ptr<b2Vec2[]> vertices;

public:
	PhysBodyShape();
	~PhysBodyShape();

	b2Vec2 * getVertices();
	void setVertices(std::vector<std::unique_ptr<b2Vec2>> const&);
	void setVert(std::vector<ShapePoint>);

	void createBodyShape(b2World&);
};

#endif