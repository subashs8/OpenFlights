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
        void adjtomat(vector<vector<pair<string,double>>>);
    private:
        vector<vector<int>> adj;
        vector<vector<int>> dist;
        vector<vector<int>> next;
        unordered_map<string, int> idx;
        int size;
};