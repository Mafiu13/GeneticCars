#include "PhysBodyShape.h"

PhysBodyShape::PhysBodyShape()
{
	vertices_ = std::make_unique<b2Vec2[]>(V);
}


PhysBodyShape::~PhysBodyShape()
{
}

void PhysBodyShape::createBodyShape(b2World& world)
{
	b2BodyDef polygonDefinition;
	polygonDefinition.type = b2_dynamicBody;
	polygonDefinition.position.Set(0, 0);
	b2Body * polygon = world.CreateBody(&polygonDefinition);

	b2PolygonShape polygonShape;
	
	polygonShape.Set(this->getVertices(), V);

	b2FixtureDef polygonFixture;
	polygonFixture.shape = &polygonShape;
	polygonFixture.density = this->getDensity();
	polygonFixture.friction = 0.3f;
	polygonFixture.restitution = 0.0;
	polygonFixture.filter.categoryBits = 0x0002;
	polygonFixture.filter.maskBits = 0x0001;

	polygon->CreateFixture(&polygonFixture);

	this->setBody(polygon);
}

void PhysBodyShape::setVerticesFromShapePoints(std::vector<ShapePoint> vec)
{
	for (int i = 0; i < vec.size(); ++i) {
		vertices_[i].x = vec[i].getX();
		vertices_[i].y = vec[i].getY();
	}
}

b2Vec2 * PhysBodyShape::getVertices() const
{
	return vertices_.get();
}
