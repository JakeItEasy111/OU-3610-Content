#include <vector>
//Answer to #7 on HW 1 
template<class T>
int seq_search(vector<T> list, const T& item, size_t size) 
{
    if (size == 0){ //no items left in list 
        return -1; 
    }
    else if (list[size - 1] == item){ //checks current position in list 
        return size - 1; 
    }
    return seq_search(list, item, size - 1); //step backward
}