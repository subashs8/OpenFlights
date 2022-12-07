#include <catch2/catch_test_macros.hpp>

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



TEST_CASE("check if map has correct size", "[weight=10][valgrind]"){
    scanner scan;
    unordered_map<string, airport> temp = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");
    REQUIRE(temp.size()==23);

}

TEST_CASE("check if there are no null cases in the data", "[weight=10][valgrind]"){
    scanner scan;
    unordered_map<string, airport> temp = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");
    int track =0;
    for (auto const &pair: temp) {
         if(pair.first=="\\N"){
             track=1;
         }
     }
     REQUIRE(track==0);
}

TEST_CASE("check size of routes vector", "[weight=10][valgrind]"){
    scanner scan;
    vector<tuple<string, string>> temp=scan.readRoutes("/workspaces/OpenFlights/lib/routes.csv");
    REQUIRE(temp.size()==37);
}

TEST_CASE("check if there are no null cases in the route vector", "[weight=10][valgrind]"){
    scanner scan;
    int track =0;
    vector<tuple<string, string>> temp=scan.readRoutes("/workspaces/OpenFlights/lib/routes.csv");
        for (auto const &pair: temp) {
        if(get<0>(pair)=="\\N"|| get<1>(pair) =="\\N"){
            track=1;
        }
    }
    REQUIRE(track==0);
}