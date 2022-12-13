#pragma once
#include "airport.h"
#include "route.h"
#include <vector>
#include <unordered_map>
using namespace std;

class traversal {
    public:
        vector<string> shortestDistance(vector<vector<pair<string,double>>> adj, vector<double> heuristic, string start, string dest); //finds shortest path
        int getIndex(string start, vector<vector<pair<string,double>>> adj); //gets index of a vertex from adjacency list
        void sortList(vector<vector<double>>& list); //sorts the 2d vector based on the third elemnts
        void createHeuristic(vector<double>& heuristic,vector<vector<pair<string,double>>> adj,map<string, airport*> table,string dest); //creates a heuristic estimate from each vertex to the destination
};