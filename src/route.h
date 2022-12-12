#pragma once
#include "airport.h"

class route {
    public:
        route(airport source, airport dest);
        double dist;
};