#include <iostream>
#include <string> 
#include "linked_list.h"
using namespace std;

int main(int argc, char** argv) {

  LinkedList<int> list;
  string ans; 
  char input; 

  while (input != 'q') {
    cout << "Please enter a command:" << endl;
    cout << "a i : Add the integer i to the front of the list. (push front)" << endl;
    cout << "d : Delete the first element of the list. (pop front)" << endl; 
    cout << "r : Reverse the list." << endl;
    cout << "p : Print the data value of each node in the list." << endl;
    cout << "q : Quit the program." << endl;

    getline(cin, ans); 
    input = ans[0]; 
    
    if (input == 'a'){

      int data = atoi(&ans[2]);

      list.push_front(data); 

    }
    else if (input == 'd'){

      list.pop_front(); 

    }
    else if (input == 'r'){

      list.reverse(); 

    }
    else if (input == 'p'){

      list.print();
      
    }
  }
  return 0; 
}
