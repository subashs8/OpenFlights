#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "scanner.h"
#include "traversal.h"
#include "utils.h"
#include "airport.h"
#include <algorithm>
#include <vector>
using namespace std;



TEST_CASE("check if map has correct size", "[weight=10][valgrind]"){
    scanner scan;
    map<string, airport*> temp = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");
    std::cout << temp.size();
    REQUIRE(temp.size()==23);

}

TEST_CASE("check if there are no null cases in the data", "[weight=10][valgrind]"){
    scanner scan;
    map<string, airport*> temp = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");
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

TEST_CASE("a star algorithim test 1", "[weight=10][valgrind]"){
    scanner scan;
    vector<vector<pair<string,double>>> adj;
    vector<pair<string,double>> temp;
    temp.push_back(make_pair("S",0));
    temp.push_back(make_pair("A",7));
    temp.push_back(make_pair("B",2));
    temp.push_back(make_pair("C",3));
    adj.push_back(temp);
    vector<pair<string,double>> temp1;
    temp1.push_back(make_pair("A",0));
    temp1.push_back(make_pair("S",7));
    temp1.push_back(make_pair("B",3));
    temp1.push_back(make_pair("D",4));
    adj.push_back(temp1);
    vector<pair<string,double>> temp2;
    temp2.push_back(make_pair("B",0));
    temp2.push_back(make_pair("S",2));
    temp2.push_back(make_pair("A",3));
    temp2.push_back(make_pair("D",4));
    temp2.push_back(make_pair("H",1));
    adj.push_back(temp2);
    vector<pair<string,double>> temp3;
    temp3.push_back(make_pair("C",0));
    temp3.push_back(make_pair("S",3));
    adj.push_back(temp3);
    vector<pair<string,double>> temp4;
    temp4.push_back(make_pair("D",0));
    temp4.push_back(make_pair("A",4));
    temp4.push_back(make_pair("B",4));
    temp4.push_back(make_pair("F",5));
    adj.push_back(temp4);
    vector<pair<string,double>> temp5;
    temp5.push_back(make_pair("E",0));
    temp5.push_back(make_pair("G",2));
    temp5.push_back(make_pair("K",5));
    adj.push_back(temp5);
    vector<pair<string,double>> temp6;
    temp6.push_back(make_pair("F",0));
    temp6.push_back(make_pair("D",5));
    temp6.push_back(make_pair("H",3));
    adj.push_back(temp6);
    vector<pair<string,double>> temp7;
    temp7.push_back(make_pair("G",0));
    temp7.push_back(make_pair("H",2));
    temp7.push_back(make_pair("E",2));
    adj.push_back(temp7);
    vector<pair<string,double>> temp8;
    temp8.push_back(make_pair("H",0));
    temp8.push_back(make_pair("B",1));
    temp8.push_back(make_pair("F",3));
    temp8.push_back(make_pair("G",2));
    adj.push_back(temp8);

    vector<double> heuristic;
    heuristic.push_back(10);
    heuristic.push_back(9);
    heuristic.push_back(7);
    heuristic.push_back(8);
    heuristic.push_back(8);
    heuristic.push_back(0);
    heuristic.push_back(6);
    heuristic.push_back(3);
    heuristic.push_back(6);

    traversal traverse;
    vector<string> output;
    output = traverse.shortestDistance(adj,heuristic,"S","E");
    const vector<string> answer = {"S","B","H","G","E"};

    REQUIRE(answer == output);
}

TEST_CASE("a star algorithim test 2", "[weight=10][valgrind]"){
    scanner scan;
    map<string, airport*> temp = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");
    vector<vector<pair<string, double>>> adj = scan.createAdj("/workspaces/OpenFlights/lib/routes.csv");

    vector<double> heuristic;

    traversal traverse;
    vector<string> output;
    traverse.createHeuristic(heuristic,adj,temp,"MRV");
    output = traverse.shortestDistance(adj,heuristic,"AER","MRV");
    const vector<string> answer = {"AER","KZN","ASF","MRV"};

    REQUIRE(answer == output);
}