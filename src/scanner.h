#pragma once
#include "airport.h"
#include "route.h"
#include <vector>
#include <unordered_map>
using namespace std;

class scanner {
    public:
        scanner();
        map<string, airport*> readAirports(const string &airportdata);
        vector<tuple<string, string>> readRoutes(const string &routedata);
        vector<vector<pair<string,double>>> createAdj(const string &routedata);
    private:
        vector<vector<string>> read(const string & filename);
        void clean(vector<vector<string>> & data);
};