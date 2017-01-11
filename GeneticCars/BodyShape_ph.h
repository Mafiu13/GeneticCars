#ifndef BODYSHAPE_PH_H 
#define BODYSHAPE_PH_H

#include <vector>
#include <memory>
#include <boost\smart_ptr\make_unique.hpp>
#include <Box2D\Box2D.h>
#include "ShapePoint.h"
#include "const.h"
#include "Element_ph.h"
#include "ShapePoint.h"

extern const float SCALE;

class BodyShape_ph: public Element_ph
{
	//tablica sprytnych wskaznikow do stworzenia nadwozia
	std::unique_ptr<b2Vec2[]> vertices;

public:
	BodyShape_ph();
	~BodyShape_ph();

	b2Vec2 * getVertices();
	void setVertices(std::vector<std::unique_ptr<b2Vec2>> const&);
	void setVert(std::vector<ShapePoint>);

	void createBodyShape(b2World &, float, float);
};

#endif