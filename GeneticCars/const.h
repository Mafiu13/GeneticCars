#ifndef CONST_H 
#define CONST_H
#include <boost\math\constants\constants.hpp>

//skala miedzy metrami, a pikselami
extern const float SCALE;
//ilosc odcnikow z ktorych sklada sie trasa
extern const int N;
//ilosc wierzchokow nadwozia pojazdow
extern const int V;
//gravity in simulation
extern const float Gravity;

//angular velocity of car's wheels
extern const float Velocity;

//factor to convert rad to degree
extern const float RADDEG;

#endif