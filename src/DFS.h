#include <vector>
using namespace std;
 
class DFS
{
public:
    vector<vector<int>> adj;
    DFS(vector<vector<int>> mat);
    bool isPath(int start, int stop, vector<bool>& visited);
};
