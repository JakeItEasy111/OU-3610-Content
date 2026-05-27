#include <iostream>
#include "huffman_tree.h"
using namespace std;

// -- TIME COMPLEXITIES --
//
// Constructing a Huffmann tree w/ Min Heap 
// O(nlogn)
// Huffmann tree construction consists of building a frequency map by going through each char in the message (n)
// + constructing a  Huffmann node for each frequency which is logm (insertion) for each m unique char 
// finally, extracting elements from this heap and building the final heap with them is O(mlogm) 
// The highest order is mlogm, therefore the entire operation is O(nlogn)
//
// If you used a linear search to find minimum frequencies, 
// time complexity would become O(n!) because all logn time minheap operations would become n time 
//

int main(int argc, char** argv) {

  HuffmanTree tree;

  int T;
  cin >> T;
  cin.ignore();
  for (int t = 1; t <= T; ++t) {
    cout << "Test Case: " << t << endl;

    string message;
    getline(cin, message);

    // Create a HuffmanTree object and read the input messages into the
    // HuffmanTree construct function. Next, print the encoded message.
    // Finally, destruct the huffman tree and move on to the next test case.
				     
    tree.construct(message);
    tree.print();
    tree.destruct();
  }

}
