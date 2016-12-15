#include "BodyShape_ph.h"

BodyShape_ph::BodyShape_ph()
{
}


BodyShape_ph::~BodyShape_ph()
{
}

void BodyShape_ph::createBodyShape(b2World & world, float x, float y, ShapePoint w[8], float density)
{
	b2BodyDef polygonDefinition;
	polygonDefinition.type = b2_dynamicBody;
	polygonDefinition.position.Set(x / SCALE, y / SCALE);
	b2Body * polygon = world.CreateBody(&polygonDefinition);

	b2PolygonShape polygonShape;
	b2Vec2 v[8];
	for (int i = 0; i < 8; ++i) {
		v[i].Set(w[i].x / SCALE, w[0].y / SCALE);

		this->vertices[i].x = w[i].x;
		this->vertices[i].y = w[i].y;
	}

	polygonShape.Set(v, 8);

	b2FixtureDef polygonFixture;
	polygonFixture.shape = &polygonShape;
	polygonFixture.density = density;
	polygonFixture.friction = 0.3f;
	polygonFixture.restitution = 0.0;

	polygon->CreateFixture(&polygonFixture);

	this->body = polygon;
}

b2Body * BodyShape_ph::getBody()
{
	return body;
}

ShapePoint * BodyShape_ph::getVertices()
{
	return vertices;
}
