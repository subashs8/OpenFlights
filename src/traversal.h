#pragma once
#include "airport.h"
#include "route.h"
#include <vector>
#include <unordered_map>
using namespace std;

class traversal {
    public:
        // vector<string> shortestDistance(vector<vector<pair<string,double>>>* adj, string start, string dest);
        // vector<vector<string>> createAdj(const string &routedata);
        int getIndex(string start, vector<vector<pair<string,double>>>* adj);
};