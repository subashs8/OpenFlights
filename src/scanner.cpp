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

scanner::scanner() {
}

map<string, airport*> scanner::readAirports(const string &airportdata) {
    vector<vector<string>> res = read(airportdata);
    clean(res);
    map<string, airport*> hashmap;
    for (size_t i = 0; i < res.size(); i++) {
        try{
            airport* temp = new airport(res[i][1], res[i][2], res[i][4], stod(res[i][6]), stod(res[i][7]));
            hashmap[res[i][4]] = temp;
        }
        catch(...){
            continue;
        }
        // cout<< temp->getName() << endl;
        
        // cout << ret[res[i][4]].getCity() << endl;
    }
    return hashmap;
}

vector<tuple<string, string>> scanner::readRoutes(const string &routedata) {
    vector<vector<string>> res = read(routedata);
    clean(res);
    vector<tuple<string, string>> ret;
    for (size_t i = 0; i < res.size(); i++) {
        ret.push_back(make_tuple(res[i][2], res[i][4]));
    }
    return ret;
}

vector<vector<pair<string,double>>> scanner::createAdj(const string &routedata) {
    scanner scan;
    

    vector<vector<string>> res = read(routedata);

    map<string, airport*> temp2 = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");

    clean(res);
    vector<vector<pair<string,double>>> adj;


    vector<bool> check;
    check.resize(res.size());
    

    for(unsigned i = 0; i < res.size(); i++){

        if(check[i] == 0){
            vector<pair<string,double>> temp;
            temp.push_back(make_pair(res[i][2], 0));
            adj.push_back(temp);
            check[i] = 1;

            for(unsigned j = 0; j < res.size(); j++){
                if(res[i][2] == res[j][2]){
                    // std::cout << temp2[res[j][4]]->getName() << " "<<temp2[res[j][4]]->getCode() << std::endl;
                    adj.back().push_back(make_pair(res[j][4], temp2[res[j][2]]->getDist(*temp2[res[j][4]])));
                    check[j] = 1;
                }
            }
        }
    }


    for(unsigned i = 0; i < adj.size();i++){
        for(unsigned j = 0; j < adj[i].size();j++){
            std::cout << adj[i][j].first << " " << adj[i][j].second << "->";
        }
        std::cout << std::endl;
    }

    return adj;
}

 vector<vector<string>> scanner::read(const string & filename) {
    string whole = file_to_string(filename);
    vector<string> rows;
    vector<vector<string>> result;
    int l = SplitString(whole, '\n', rows);
    result.resize(l);
    for (int r = 0; r < l; r++) {
        int l2 = SplitString(rows[r], ',', result[r]);
        for (int w = 0; w < l2; w++) {
            result[r][w] = Trim(result[r][w]);
        }
    }
    return result;
 }

 void scanner::clean(vector<vector<string>> & data) {
    for (size_t i = 0; i < data.size(); i++) {
        if (find(data[i].begin(), data[i].end(), "\\N") != data[i].end()) {
            data.erase(data.begin() + i, data.begin() + i + 1);
        }
    }
 }