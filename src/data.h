#pragma once
#include "route.h";
using namespace std;

class data {
    public:
        data();
        unordered_map<string, Airport> lookup;
        vector<tuple<string, string, route>> adj;
};