#include "binary_tree.h"
#include <stack>
using namespace std;

template <class elemType>
int singleParent(binaryTreeNode<elemType> *p) {
    if (p != nullptr){

        if((p->llink == nullptr) !=  (p->rlink == nullptr)){
            return 1 + singleParent(p->llink) + singleParent(p->rlink); 
        }
        else 
        {
            return singleParent(p->llink) + singleParent(p->rlink); 
        }
    }
    else 
    {
        return 0; 
    }
}; 

template <class elemType>
int singleParentIterative(binaryTreeNode<elemType> *p) {
    if(p == nullptr) return 0;

    int num_single_parents = 0; 
    stack<binaryTreeNode<elemType>*> st; 

    do {
        //go left as possible 
        while(p != nullptr=){
            
            //check for single parent 
            if ((p->llink == nullptr) !=  (p->rlink == nullptr)){
                ++num_single_parents;
            }

            //left subtree
            st.push(p); 
            p = p->llink; 
                
        } 

        //right subtree
        if (!st.empty())
        {
            p = st.top(); 
            st.pop(); 
            p = p->rlink; 
        }
    } while (!st.empty() || p! = nullptr );

    return num_single_parents;
}; 