#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <queue>
#include <unordered_map>
#include <cctype>



#include "scanner.h"
#include "utils.h"
#include "floyd.h"
#include "dfs.h"
#include "airport.h"
#include <algorithm>
#include <vector>
#include "traversal.h"
using namespace std;

int main() {
    scanner scan;
    map<string, airport*> temp = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");
    vector<vector<pair<string, double>>> adj = scan.createAdj("/workspaces/OpenFlights/lib/routes.csv");
    traversal traverse;
    floyd f;
    vector<vector<int>> mat = f.adjtomat(adj);
    unordered_map<string, int> idx = f.getIdx();
    DFS dfs(mat);
    


    
    vector<double> heuristic;

    vector<string> output;
    std::cout << "Choose from the following airports:" << std::endl;
    for(unsigned i = 0; i < adj.size();i++){
        if(i == adj.size()-1){
            std::cout << adj[i][0].first;
        }else{
            std::cout << adj[i][0].first << ", ";
        }
    }
    std::cout << std::endl;
    string start;
    string dest;
    std::cout << "Enter Starting Airport: ";
    std::cin >> start;
    std::transform(start.begin(), start.end(), start.begin(), ::toupper);
    bool check1 = false;
    for(unsigned i = 0; i < adj.size();i++){
        if(start == adj[i][0].first){
            check1 = true;
        }
    }
    if(!check1){
        std::cout << "Invalid airport. Please try again." << std::endl;
        return 0;
    }
    std::cout << "Enter Destination Airport: ";
    std::cin >> dest;
    std::transform(dest.begin(), dest.end(), dest.begin(), ::toupper);
    bool check2 = false;
    for(unsigned i = 0; i < adj.size();i++){
        if(dest == adj[i][0].first){
            check2 = true;
        }
    }
    if(!check2){
        std::cout << "Invalid airport. Please try again." << std::endl;
        return 0;
    }
    vector<bool> v;
    if  (dfs.isPath(idx[start], idx[dest], v)) {
    cout << "Would you like to use A* or Floyd-Warshall, type y for A* and n for Floyd-Warshall: " << endl;
    string alg;
    cin >> alg;
    if (alg == "y") {
    traverse.createHeuristic(heuristic,adj,temp,dest);
    output = traverse.shortestDistance(adj,heuristic,start,dest);

    std::cout << "This is the shortest path between " << start << " airport" << " and " << dest << " airport using A* algorithim" << std::endl;
    for(unsigned i = 0; i < output.size(); i++){
        if(i == output.size()-1){
            std::cout << output[i] << std::endl;
        }else{
            std::cout << output[i] << " -> ";
        }
    }
    }
    else if (alg == "n") {
    f.init();
    f.floydw();
    vector<string> path;
    path = f.createPath(start, dest);
    int n = path.size();
    cout << "This is the route using Floyd-Warshall Algorithm" << endl;
    for (int i = 0; i < n - 1; i++)
        cout << path[i] << " -> ";
    cout << path[n - 1] << endl;
    }
    }
    else {
        cout << "Path Does Not Exist" << endl;
    }
}