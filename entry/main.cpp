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
using namespace std;

int main() {
    scanner scan;
    unordered_map<string, airport> temp = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");
    vector<tuple<string, string>> temp2 = scan.readRoutes("/workspaces/OpenFlights/lib/routes.csv");
    for (auto const &pair: temp) {
        std::cout << "{" << pair.first << "}\n";
    }
    for (auto const &pair: temp2) {
        std::cout << "{" << get<0>(pair) << ", " << get<1>(pair) << "}\n";
    }
    cout << temp.at("SFJ").getName() << endl;

}