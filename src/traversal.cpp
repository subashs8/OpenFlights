#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <queue>

#include "scanner.h"
#include "utils.h"
#include "DFS.h"
#include "airport.h"
#include "traversal.h"
#include <algorithm>
#include <vector>

int traversal::getIndex(string start, vector<vector<pair<string,double>>> adj){
    //returns the index of the vertex in the adjacency list
    for(unsigned i =0; i< adj.size();i++){
        if(start==adj[i][0].first){
            return i;
        }
    }
    return 0;
}

void traversal::sortList(vector<vector<double>>& list){
    //sorts a 2d vector based on the third element of each vector
    std::sort(list.begin(), list.end(),[] (const std::vector<double> &a, const std::vector<double> &b)
              {
                  return a[2] < b[2];
              });
    
}

void traversal::createHeuristic(vector<double>& heuristic, vector<vector<pair<string,double>>> adj, map<string, airport*> table, string dest){
    //creates a heuristic estimate by calculating distance from every vertex to the destination vertex
    for(unsigned i = 0; i < adj.size(); i++){
        heuristic.push_back(table[(adj[i][0]).first]->getDist(*table[dest]));
    }
}


vector<string> traversal::shortestDistance(vector<vector<pair<string,double>>> adj, vector<double> heuristic, string start, string dest){
    vector<string> output; //the path output
    vector<vector<double>> explored; // stores the curr index, prev_dist, combined heuristic, prev_node
    vector<vector<double>> unexplored; // stores the curr index, prev_dist, combined heuristic, prev_node 


    vector<double> temp;
 
    temp.push_back(getIndex(start,adj)); //stores the index of start from the adjacency list
    temp.push_back(0); //distance from start vertex to itself
    temp.push_back(heuristic[getIndex(start,adj)]); //the combined heuristic
    temp.push_back(-1); //previous vertex of start is set to -1
    unexplored.push_back(temp);

    string currIndex =start;
    while(heuristic[unexplored[0][0]] != 0){ //until the destination vertex is at the top of the unexplored list it loops
        int index = getIndex(currIndex,adj); //gets the index of vertex from adjacency list
        vector<double> temp2=unexplored[0]; //temp2 is set to the vertex at the top of the unexplored list
        for(unsigned i=1;i<adj[index].size();i++ ){ //explores each adjacent vertex in the adjacency list
            bool explored_check = false;
            bool unexplored_check = false;
            for(unsigned j=0; j < explored.size();j++){ //checks if the vertex has been explored
                if(adj[index][i].first == adj[explored[j][0]][0].first){
                    explored_check = true;
                }
            }
            int curr_neighbor = 0;
            for(unsigned k=0; k < unexplored.size();k++){ //checks if the vertex is currently in the unexplored list
                if(adj[index][i].first == adj[unexplored[k][0]][0].first){
                    unexplored_check = true;
                    curr_neighbor = k; //returns the index of the adjacent vertex in the unexplored list
                }

            }
               
                
            //check if the neighbour has been visited if not push to unexplored
            if(explored_check == false && unexplored_check == false){ // if the adjacent vertex isn't in explored or unexplored list
                vector<double> temp;
                temp.push_back(getIndex(adj[index][i].first,adj)); // adds the index of the adjacent vertex
                temp.push_back(temp2[1]+adj[index][i].second); //pushes the sum of distance to the previous vertex and its adjacent vertex
                temp.push_back(temp2[1]+adj[index][i].second+heuristic[getIndex(adj[index][i].first,adj)]); // pushes the combined heuristic value
                temp.push_back(index); //pushes the index of the previous vertex
                unexplored.push_back(temp);
                sortList(unexplored); //sorts the list so that the vertex with the lowest combined heuristic is at top
            }
            if(temp2[1]+adj[index][i].second<unexplored[curr_neighbor][1] && unexplored_check == true && explored_check == false){ //if there is a shorter distance to an adjacent vertex
                unexplored[curr_neighbor][1] = temp2[1]+adj[index][i].second; //new updated distance
                unexplored[curr_neighbor][2] = temp2[1]+adj[index][i].second+heuristic[getIndex(adj[index][i].first,adj)];//new updated combined heuristic
                unexplored[curr_neighbor][3] = index; //new updated previous vertex index
            }
                
            
        }
        explored.push_back(temp2);//once the current vertex's adjacent vertex are all visited, the current vertex is added to the explore list
        for(unsigned k=0; k < unexplored.size();k++){//removes the current vertex from the unexplored list
            if(adj[index][0].first == adj[unexplored[k][0]][0].first){
                unexplored.erase(unexplored.begin()+k); 
            }

        }
        currIndex = adj[unexplored[0][0]][0].first; //the current index is set to the vertex with the lowest combined heuristic value

    }

    bool check = false;
    output.push_back(adj[unexplored[0][0]][0].first);//pushes the destination vertex to output
    int i = unexplored[0][3];//i is set to the previous vertex
    while(!check){
        int temp = 0;
        for(unsigned k=0; k < explored.size();k++){//finds the vertex with index i in the unexplored list
            if(adj[i][0].first == adj[explored[k][0]][0].first){
                temp = k;
            }    
        }
            
        output.push_back(adj[explored[temp][0]][0].first);//pushes the vertex to output
        i = explored[temp][3];//i is set to the index of previous vertex
        if(i == -1){//if i is -1 that means we have arrived at the start vertex so while loop ends
            check = true;
        }
        
    }

    std::reverse(output.begin(), output.end());//reverses the output so that it shows most efficent path


    return output;
}
