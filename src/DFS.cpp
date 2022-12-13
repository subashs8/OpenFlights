#include "DFS.h"
#include <vector>
using namespace std;
const int MAX = 1000000;
DFS::DFS(vector<vector<int>> mat) {
    adj = mat;
}

bool DFS::isPath(int start, int stop, vector<bool>& visited) {
    visited.resize(adj.size());
    visited[start] = true;
    for (size_t i = 0; i < adj[start].size(); i++) {
        if (adj[start][i] != MAX && visited[i] != true) {
            if ((int)i == stop) {
                return true;
            }
            else {
                if (isPath(i, stop, visited)) {
                    return true;
                }
            }
        }
    }

    return false;
}