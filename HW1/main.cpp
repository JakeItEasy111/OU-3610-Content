#include <iostream>
#include <string> 
#include <vector>
#include "stdev.h"
#include "seq_search.h"
using namespace std;


int main(int argc, char** argv) {
    string ans; 
    vector<float> list; 

    cout << "Enter numbers for the list and enter q when finished." << endl; 

    while(true){

        cin >> ans; 

        if (ans == "q"){ break; }

        float item = stof(ans);
        list.push_back(item);
    }

    cout << "Type search to find an item" << endl << 
    "Type stdev to find the standard deviation of numbers" << endl <<
     "Type avg to average numbers" << endl <<
     "Type q to quit program" << endl; 
    
    ans = " ";  
    while (ans != "q"){

        cin >> ans; 

        if (ans == "search"){
            cout << "Enter target: "; 
            cin >> ans; 
            float target = stof(ans); 
            cout << endl << "Index of target is " << seq_search(list, target, list.size()) << endl; 
        }

        if (ans == "avg"){
            cout << find_mean(list) << endl; 
        }
        
        if (ans == "stdev"){
            cout << find_stdev(list) << endl; 
        }
    }
}
