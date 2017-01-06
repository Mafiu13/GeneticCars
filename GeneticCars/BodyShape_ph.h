#ifndef BODYSHAPE_PH_H 
#define BODYSHAPE_PH_H

#include <vector>
#include <memory>
#include <boost\smart_ptr\make_unique.hpp>
#include <Box2D\Box2D.h>
#include "ShapePoint.h"
#include "const.h"
#include "Element_ph.h"

extern const float SCALE;

class BodyShape_ph: public Element_ph
{
	//tablica sprytnych wskaznikow do stworzenia trasy
	std::unique_ptr<b2Vec2[]> vertices;

public:
	BodyShape_ph();
	~BodyShape_ph();

	b2Vec2 * getVertices();
	void setVertices(std::vector<std::unique_ptr<b2Vec2>> const&);

	void createBodyShape(b2World &, float, float, float);
};

#endif