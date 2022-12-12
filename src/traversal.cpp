#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>

#include "scanner.h"
#include "utils.h"
#include "airport.h"
#include "traversal.h"
#include <algorithm>
#include <vector>

int traversal::getIndex(string start, vector<vector<pair<string,double>>>* adj){
   vector<vector<pair<string,double>>> a = *adj;
    for(unsigned i =0; i< adj->size();i++){
        if(start==a[i][0].first){
            return i;
        }
    }
    return -1;
}


// vector<string> traversal::shortestDistance(vector<vector<pair<string,double>>>* adj, string start, string dest){
//     vector<string> output;
//     vector<vector<double>> explored; // curr index, prev_dist, combined_h, prev_node
//     vector<vector<double>> unexplored; // prev_dist, combined_h, prev_node
//     vector<double> heuristic;


//     scanner scan;
//     vector<vector<pair<string,double>>> a = *adj;
//     map<string, airport*> temp2 = scan.readAirports("/workspaces/OpenFlights/lib/airports.csv");

//     for(unsigned i = 0; i < adj->size(); i++){
//         heuristic.push_back(temp2[(a[i][0]).first]->getDist(*temp2[dest]));
//     }

//     // for(unsigned i = 0; i < heuristic.size(); i++){
//     //     std::cout << heuristic[i] << std::endl;
//     // }
//     vector<double> temp;
//     temp.push_back(getIndex(start,adj));
//     temp.push_back(0);
//     temp.push_back(0+heuristic[getIndex(start,adj)]);
//     temp.push_back(-1);
//     unexplored.push_back(temp);

//     // for(unsigned i =0;i<temp.size();i++){
//     //     std::cout<<temp[i]<<std::endl;
//     // }
//     string currIndex =start;
//     while(heuristic[unexplored[0][0]] != 0){
//         int index = getIndex(currIndex,adj);
//         for(unsigned i=1;i<a[index].size();i++ ){
//             vector<double> temp2=unexplored.back();
//             bool explored_check = false;
//             bool unexplored_check = false;
//             for(unsigned j=0; j < explored.size();j++){
//                 if(a[index][i].first == a[explored[j][0]][0].first){
//                     explored_check = true;
//                 }
//             }

//             for(unsigned k=0; k < unexplored.size();j++){
//                 if(a[index][i].first == a[unexplored[k][0]][0].first){
//                     unexplored_check = true;
//                 }
//             }
               
                

//                 if(explored_check == false && unexplored_check == false){
//                     vector<double> temp;
//                     temp.push_back(getIndex(a[index][i].first,adj));
//                     temp.push_back(temp2[1]+a[index][i].second);
//                     temp.push_back(temp2[1]+a[index][i].second+heuristic[getIndex(a[index][i].first,adj)]);
//                     temp.push_back(index);
//                     unexplored.push_back(temp)
//                 }
//                 if(temp2[1]<unexplored[getIndex(a[index][i].first)][1] && unexplored_check = true){
//                     unexplored[getIndex(a[index][i].first)][1]=temp2[1]+a[index][i].second;
//                     unexplored[getIndex(a[index][i].first)][2]=temp2[1]+heuristic[getIndex(start,adj)];

//                 }
                
            
//             //check if the neighbour has been visited
//             //if not visited then push to unexplored
            
//         }
//         //once all neigbours pushed pop the vertex and push it to explored
//         //order the vector based on the sum
//         //update currIndex to the top of the unexplored
//     }


//     return output;
// }
