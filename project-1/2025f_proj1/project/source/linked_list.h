
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {

public:
  LinkedList() : head(NULL) {}

  // You need to implement the following functions. 
  // 
  ~LinkedList();
  void push_front(const T data);
  void pop_front();
  void reverse();
  void print() const;

private:
  
  struct ListNode {
    ListNode(const T data) : data(data), next(NULL) {}
    
    T data;
    ListNode* next;
  };

  ListNode* head;
};

#include "linked_list.template"