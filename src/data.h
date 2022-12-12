#pragma once
#include "route.h";
#include "airport.h"
using namespace std;

class data {
    public:
        data();
        unordered_map<string, Airport> lookup;
        vector<vector<airport>> adj;
};