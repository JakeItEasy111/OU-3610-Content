#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using std::priority_queue for heap operations, as it uses a heap data structure internally

int partition(vector<int>& list, int first, int last) {
  // The pivot should be the median of the
  // first, middle, and last elements.
  int pivotIndex = (first + last) / 2;
  if (list[first] > list[pivotIndex]) swap(list[first], list[pivotIndex]);
  if (list[first] > list[last]) swap(list[first], list[last]);
  if (list[pivotIndex] > list[last]) swap(list[pivotIndex], list[last]);

  int pivot; 
  int smallIndex = first; //keeps track of the last number smaller than pivot, which separates smaller and bigger nums 

  //move pivot to start  
  swap(list.at(first), list.at(pivotIndex));
  pivot = list.at(first);
  smallIndex = first; 

  ////move smaller elements to the lower sublist
  for (int i = first + 1; i <= last; i++)
  {
    if (list.at(i) < pivot) 
    {
      smallIndex++;
      swap(list.at(smallIndex), list.at(i));
    }
  }

  //return partition to its place  
  swap(list.at(first), list.at(smallIndex)); 
  return smallIndex; 
}

void quicksort(vector<int>& list, int first, int last) {
  int pivotLocation;

  if (first < last)
  {
    pivotLocation = partition(list, first, last); //partition into sublists
    quicksort(list, first, pivotLocation -1); //quicksort smaller sublist
    quicksort(list, pivotLocation + 1, last); //quicksort larger sublist 
  }
}

void multiway_merge(
  vector<vector<int> >& input_lists, vector<int>& output_list
) 
{
  
  using Node = pair<int, vector<int>*>; 
  //int is the index of the heap key, the vector is the originating list of the key 

  struct Compare {
      bool operator()(const Node& x, const Node& y) const {
          // Compare two smallest integers
          return x.second->at(x.first) > y.second->at(y.first); 
      }
  };

  priority_queue<Node, vector<Node>, Compare> min_heap;

  //build min heap of first element of each sorted sublist 
  for (vector<int>& list : input_lists)
  {
    if (!list.empty())
    {
      min_heap.emplace(pair(0, &list)); 
    }
  }

  int output_index = 0; 

  //extract, replace, heapify until nothing remains in the heap 
  while(!min_heap.empty()) 
  {

    //remove from original list, replace with sucessor and add back list (which will heapify)
    Node smallest_pair = min_heap.top(); 
    min_heap.pop();
    
    //add smallest int to output list 
    output_list[output_index++] = smallest_pair.second->at(smallest_pair.first);

    smallest_pair.first++; //increase index of smallest_int belonging to this list 

    //if index is within size of originating list 
    if (smallest_pair.first < smallest_pair.second->size()) {
      min_heap.emplace(smallest_pair);
    }
    
  }
} 

int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > input_lists(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input_lists[i][j];
    }
  }

  // Quicksort k sublists
  for (int i = 0; i < input_lists.size(); ++i)
    quicksort(input_lists[i], 0, m-1);

  // Merge n input sublists into one sorted list
  vector<int> output_list(n * m);
  multiway_merge(input_lists, output_list);

  for (int i = 0; i < output_list.size(); ++i)
    cout << output_list[i] << " ";
  cout << endl;

  return 1;
}
