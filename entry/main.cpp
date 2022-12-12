#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "scanner.h"
#include "utils.h"
#include "airport.h"
#include <algorithm>
#include <vector>
#include "floyd.h"
using namespace std;

const int MAX = 1000000;

void printPath(vector<string>& path)
{
    int n = path.size();
    for (int i = 0; i < n - 1; i++)
        cout << path[i] << " -> ";
    cout << path[n - 1] << endl;
}

int main() {
 
    int V = 4;
    vector<vector<int>> grsdaaph = {{0,3,MAX,7}, {8,0,2,MAX},{5,MAX,0,1}, {2,MAX,MAX, 0}};
    scanner scan;
    vector<vector<pair<string, double>>> graph = scan.createAdj("/workspaces/OpenFlights/lib/routes.csv");

    // Function to initialise the
    // distance and Next array
    floyd f;
    f.adjtomat(graph);
    f.init();
    // Calling Floyd Warshall Algorithm,
    // this will update the shortest
    // distance as well as Next array
    f.floydw();
    vector<string> path;
 
    // Path from node 1 to 3
    cout << "Shortest path from 1 to 3: ";
    path = f.createPath("GYD", "MRV");
    printPath(path);
    return 0;
}

// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <map>
// #include <unordered_map>

// #include "scanner.h"
// #include "utils.h"
// #include "airport.h"
// #include <algorithm>
// #include <vector>
// #include "traversal.h"
// using namespace std;

// int main() {
//     scanner scan;
//     map<string, airport*> temp = scan.readAirports("/workspaces/OpenFlights/lib/1.csv");
//     // // vector<tuple<string, string>> temp2 = scan.readRoutes("/workspaces/OpenFlights/lib/routes.csv");
//     // //temp["AER"];
//     // std::cout << temp["DME"]->getDist(*temp["CEK"]) << std::endl;

//     vector<vector<pair<string, double>>> temp2 = scan.createAdj("/workspaces/OpenFlights/lib/routes.csv");
//     traversal traverse;
//     // traverse.shortestDistance(&temp2, "AER", "MRV");
//     // for (auto const &pair: temp) {
//     //     std::cout << "{" << pair.first << "}\n";
//     //     // std::cout << "{" << (pair.second).getCity() << "}" << endl;
//     // }
//     // for (auto const &pair: temp2) {
//     //     std::cout << "{" << get<0>(pair) << ", " << get<1>(pair) << "}\n";
//     // }
//     // cout << temp.at("SFJ").getName() << endl;

// }