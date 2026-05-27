#include <iostream>
#include <vector>
#include "weightedgraphtype.h"
using namespace std;

int main(int argc, char** argv) {

    int cases; 
    cin >> cases; 

    for (int c = 0; c < cases; c++){

        //first line of each case is the number of cities n in the graph (gSize, size of graph) 
        int size; 
        cin >> size; 
        weightedGraphType dijsktra = weightedGraphType(size); 

        //create remainder of graph
        dijsktra.createWeightedGraph(); 

        //Find shortest path from city 1 to city n for all n 
        dijsktra.shortestPath(0); 

        // city1 city2 cityn dist 
        dijsktra.printShortestPath(size - 1); 
        dijsktra.printShortestDistance(size - 1); 
        cout << endl; 
    }

    return 1; 
}