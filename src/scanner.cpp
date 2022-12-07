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

unordered_map<string, airport> scanner::readAirports(const string &airportdata) {
    vector<vector<string>> res = read(airportdata);
    clean(res);
    unordered_map<string, airport> ret;
    for (size_t i = 0; i < res.size(); i++) {
        airport temp(res[i][1], res[i][2], res[i][4], stod(res[i][6]), stod(res[i][7]));
        ret.insert(make_pair(res[i][4], temp));
    }
    return ret;
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