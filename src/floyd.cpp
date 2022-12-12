#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "floyd.h"
using namespace std;

const int MAX = 1000000;

floyd::floyd() {
    size = 0;
}

void floyd::adjtomat(vector<vector<pair<string,double>>> graph) {
    adj.resize(graph.size());
    for (size_t i = 0; i < graph.size(); i++) {
        vector<int> temp1;
        temp1.resize(graph.size());
        adj[i] = temp1;
    }
    for (size_t i = 0; i < graph.size(); i++) {
        idx[graph[i][0].first] = (int)i;
    }
    for (size_t i = 0; i < graph.size(); i++) {
        int curridx = idx[graph[i][0].first];
        for (size_t j = 1; j < graph[i].size(); j++) {
            int nextidx = idx[graph[i][j].first];
            adj[curridx][nextidx] = graph[i][j].second;
        }
    }
    for (size_t i = 0; i < adj.size(); i++) {
        for (size_t j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == 0) {
                adj[i][j] = MAX;
            }
        }
    }
}

void floyd::init() {
    size = adj.size();
    dist.resize(size);
    next.resize(size);
    for (int i = 0; i < size; i++) {
        vector<int> temp1;
        temp1.resize(size);
        dist[i] = temp1;
        vector<int> temp2;
        temp2.resize(size);
        next[i] = temp2;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dist[i][j] = adj[i][j];
            if (adj[i][j] == MAX) {
                next[i][j] = -1;
            }
            else { 
                next[i][j] = j;
            }
        }
    }
}

void floyd::floydw() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {  
                if (dist[j][i] == MAX || dist[i][k] == MAX) {
                    continue;
                }
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    next[j][k] = next[j][i];
                }         
            }
        }   
    }
}

vector<string> floyd::createPath(string start, string stop) {
    int a = idx[start];
    int b = idx[stop];
    vector<string> path;
    if (next[a][b] == -1)
        return path;
    path.push_back(start);
    while (a != b) {
        a = next[a][b];
        string n;
        for(auto pair : idx) {
            if (pair.second == a) {
                n = pair.first;
                break;
            }
        }
        path.push_back(n);
    }
    return path;
}


