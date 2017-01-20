#include "PhysBodyShape.h"

PhysBodyShape::PhysBodyShape()
{
	vertices_ = std::make_unique<b2Vec2[]>(NR_OF_POINTS_IN_BODYSHAPE);
}


PhysBodyShape::~PhysBodyShape()
{
	b2World * world = getBody()->GetWorld();
	world->DestroyBody(getBody());
}

void PhysBodyShape::createBodyShape(b2World& world)
{
	b2BodyDef polygonDefinition;
	polygonDefinition.type = b2_dynamicBody;
	polygonDefinition.position.Set(0, 0);
	b2Body * polygon = world.CreateBody(&polygonDefinition);

	b2PolygonShape polygonShape;
	
	polygonShape.Set(this->getVertices(), NR_OF_POINTS_IN_BODYSHAPE);

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
