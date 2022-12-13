#pragma once
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class floyd {
    public:
        floyd();
        void init();
        vector<string> createPath(string start, string stop);
        void floydw();
        vector<vector<int>> adjtomat(vector<vector<pair<string,double>>>);
        unordered_map<string, int> getIdx();
    private:
        vector<vector<int>> adj;
        vector<vector<int>> dist;
        vector<vector<int>> next;
        unordered_map<string, int> idx;
        int size;
};