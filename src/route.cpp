#include "route.h"
#include "airport.h"
#include <algorithm>
#include "math.h"
using namespace std;


route::route(airport source, airport dest) {
    double x = source.getLat() - dest.getLat();
    double y = source.getLon() - dest.getLon(); 
    x = x * x;
    y = y * y;
    this->dist = sqrt(x + y);
}