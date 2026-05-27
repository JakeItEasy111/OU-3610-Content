#include <fstream>
#include <vector>
#include <limits.h>
using namespace std; 

// instead of using a weight matrix, i opted for an adjacency list where edges have an associated weight
// simpler to read, more efficient for sparser graphs 
// Ex: graph > city > name, edges > edge<int neighbor, int weight> 
struct City {
    string name;
    vector<pair<int,int>> edges;  
};

class weightedGraphType
{
public:

    //Postcondition: Returns true if the graph is empty;
    // otherwise, returns false.
    bool isEmpty() const{
        return gSize == 0; 
    };

    //Postcondition: Each vector of pairs is cleared and memory deallocated 
    void clearGraph(){
        for(int i = 0; i < gSize; i++){
            graph[i].edges.clear(); 
        }
        graph.clear(); 
        smallestWeight.clear(); 
        gSize = 0; 
    };

    //Postcondition: The graph is printed.
    void printGraph() const
    {
        for (int i = 0; i < gSize; i++)
        {
            cout << graph[i].name; 

            for(int j = 0; j < graph[i].edges.size(); j++)
            {
                cout << " (" << graph[graph[i].edges[j].first].name << ", " << graph[i].edges[j].second << ")"; 
            }

            cout << endl; 
        }
    }

    //Creates weighted graph using adjacency lists 
    void createWeightedGraph()
    {
        // Next n lines are city names 
        for (int i = 0; i < gSize; i++){
            cin >> graph[i].name; 
        }
        
        // n x n space delimited matrix of weights 
        // symmetric matrix, so no need to add to both 
        int weight;
        for (int i = 0; i < gSize; i++) 
        {
            for (int j = 0; j < gSize; j++)
            {
                cin >> weight;

                if (weight == 0) continue; 

                graph[i].edges.push_back({j, weight}); 
            }
                
        }
    }

    // Stores the distance from the origin denoted by vertex to **every other city**
    // Modified so that the actual path (the sequence of cities) is stored with predecessor[] 
    void shortestPath(int vertex)
    {
        if (isEmpty()) return; 

        //initialize neighbors of vertex 
        for (pair<int, int> &p : graph[vertex].edges)
        {
            int neighbor = p.first;
            int weight = p.second; 
            smallestWeight[neighbor] = weight; 
            predecessor[neighbor] = vertex; 
        }
                    
        //set of cities whose shortest path is found 
        vector<bool> weightFound = vector<bool>(gSize, false);

        //source shortest path to itself is 0
        weightFound[vertex] = true; 
        smallestWeight[vertex] = 0; 

        //find shortest path to each city 
        for (int i = 0; i < gSize - 1; i++){
            int minWeight = INT_MAX; //shortest path weight 
            int nextSmallest = -1; //index of next closest vertex in the graph 

            //linear search to find the undetermined vertex w/ smallest distance from origin
            for (int j = 0; j < gSize; j++) 
            {
                if (!weightFound[j] && (smallestWeight[j] < minWeight)) 
                {
                    nextSmallest = j;
                    minWeight = smallestWeight[nextSmallest];
                }
            }
            
            if (nextSmallest == -1)
            {
                break; 
            }

            weightFound[nextSmallest] = true; //smallest distance now known

            // Check each adjacent edge, if shorter than the current shortest path for that city
            // then set smallestWeight for that neighbor city 
            for (pair<int, int> &p : graph[nextSmallest].edges)
            {
                int neighbor = p.first; 
                int edgeWeight = p.second;
                if (!weightFound[neighbor])
                {
                    int pathWeight = minWeight + edgeWeight;

                    if(pathWeight < smallestWeight[neighbor])
                    {
                        smallestWeight[neighbor] = pathWeight; 
                        predecessor[neighbor] = nextSmallest; 
                    }
                }
            }
        }
    }

    //Print shortest distance from origin to vertex 
    void printShortestDistance(int vertex)
    {
        cout << smallestWeight[vertex]; 
    }

    //recursively print path using predecessor 
    void printShortestPath(int vertex)
    {
        if (vertex >= gSize){
            return; 
        }

        if (predecessor[vertex] == -1)
        {
            cout << graph[vertex].name << " ";
            return;
        }

        printShortestPath(predecessor[vertex]); 

        cout << graph[vertex].name << " "; 
    }

    //Constructor 
    weightedGraphType(int size = 0){
        gSize = size; 
        graph = vector<City>(size);
        smallestWeight = vector<int>(size, INT_MAX);
        predecessor = vector<int>(size, -1);
    }; 

    //Destructor
    ~weightedGraphType(){
        clearGraph(); 
    }; 

protected:
    int gSize; //current number of vertices
    vector<City> graph; //array to create adjacency lists
    vector<int> smallestWeight; //array to store smallest weights from source to vertices
    vector<int> predecessor; //array to store the predecessor of each vertex on its shortest path from source 
};