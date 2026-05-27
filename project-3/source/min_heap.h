#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}
  bool operator<(const HeapNode<T>& rhs) {return this->key < rhs.key;}
  bool operator<=(const HeapNode<T>& rhs) {return this->key <= rhs.key;}
  bool operator >(const HeapNode<T>& rhs) {return this->key > rhs.key;}

  T data;
  int key;
};

template <typename T>
class MinHeap {
public:
  MinHeap() {}
  ~MinHeap() {}

  void insert(const T data, const int key);
  T extract_min();
  T peek() const; // need to implement this function

  int size() const;         // need to implement this function

private:
  vector<HeapNode<T> > heap;
};


//  Insert the provided user data into the min heap using the provided key to make
//  comparisons with the other elements in the min heap

//  To ensure that your min heap produces consistent results, stop bubbling up a
//  child node if it shares the same key value as its parent node.
template <typename T>
void MinHeap<T>::insert(const T data, const int key) 
{  
    HeapNode<T> inserted_node = HeapNode(data, key);
    heap.push_back(inserted_node);
    size_t i = size() - 1; //start at last node

    while((i > 0) && (key < heap[(int)floor((i-1)/2)].key)) //while to-be-inserted node's key is less than current node's key 
    {
        int parent_index = (int)floor((i-1)/2);
        swap(heap[i], heap[parent_index]); 
        i = parent_index;                
    }
}

// Remove from the min heap the element with the smallest key value and return
// its data.
// If you come across two sibling nodes that share the same key value while sifting
// down a parent node with a larger key value, then you should swap the parent
// node with the left child to ensure that your min heap produces consistent results.
template <typename T>
T MinHeap<T>::extract_min() {                         

    if (heap.empty())
    {
        return T{}; 
    }

    //store min data and replace min with last node 
    T min = peek();  
    HeapNode<T> last = heap.back(); 
    heap.pop_back(); 

    if(heap.empty()) { return min; } //check after pop 

    size_t i = 0; //parent
    size_t j = 1; //smallest child

    heap[i] = last; 

    //Ensure j is smallest child
    if (j+1 < size()) 
    {
        if (heap[j] > heap[j+1]) 
        {
            j++;
        } 
    }

    //bubble down if smallest of children is smaller 
    while ((j < size()) && (heap[i] > heap[j])) //while min is greater than j 
    {
        swap(heap[i], heap[j]); 
        i = j; //parent becomes smallest child 
        j = 2*i + 1; //subtrees become 2i + 1 

        //Ensure j is always smallest child  
        if (j+1 < size()) 
        {
            if (heap[j] > heap[j+1]) 
            {
                j++;
            }  
        }
    }
    
    return min;
}

// Retrieve the minimum element in the min heap and return its data to the user.
// Do not remove this element from the min heap in this function.
template <typename T>
T MinHeap<T>::peek() const 
{
    if(!heap.empty())
    {
        return heap[0].data;
    }
    return nullptr; 
}

// Return the size of the min heap 
template <typename T>
int MinHeap<T>::size() const 
{
    return heap.size(); 
}
