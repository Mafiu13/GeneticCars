#ifndef CARCONST_H 
#define CARCONST_H
#include <boost/math/constants/constants.hpp>

const static int NR_OF_POINTS_IN_BODYSHAPE = 8;
const static int NR_OF_WHEELS = 2;

const static float DENSITY_MIN = 0.1f;
const static float DENSITY_MAX = 1.0f;

const static float POINT_MIN = -2.0f;
const static float POINT_MAX = 2.0f;

const static float RADIUS_MIN = 0.3f;
const static float RADIUS_MAX = 1.3f;

const static float SCALE = 50.0f;
const static float RADDEG = 180.0f / boost::math::constants::pi<float>();

const static float VELOCITY = 20.0f;

#endif
