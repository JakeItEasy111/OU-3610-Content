//Definition of the node
template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

//Definition of the class
template <class elemType>
class binaryTreeType
{
    public:
        const binaryTreeType<elemType>& operator =
        (const binaryTreeType<elemType>&);
        //Overload the assignment operator.

        bool isEmpty() const {
            return (root == NULL);
        }
        //Returns true if the binary tree is empty;
        //otherwise, returns false.

        void inorderTraversal() const{
            inorder(root);
        }
        //Function to do an inorder traversal of the binary tree.

        void preorderTraversal() const{
            preorder(root);
        }
        //Function to do a preorder traversal of the binary tree.

        void postorderTraversal() const{
            postorder(root);
        }
        //Function to do a postorder traversal of the binary tree.

        int treeHeight() const{
            return height(root);
        }
        //Returns the height of the binary tree.

        int treeNodeCount() const{
            return nodeCount(root);
        }
        //Returns the number of nodes in the binary tree.

        int treeLeavesCount() const{
            return leavesCount(root);
        }
        //Returns the number of leaves in the binary tree.

        void destroyTree();
        //Deallocates the memory space occupied by the binary tree.
        //Postcondition: root = NULL;

        binaryTreeType(const binaryTreeType<elemType>& otherTree);
        //copy constructor

        binaryTreeType(){
            root = NULL;
        }
        //default constructor

        ~binaryTreeType();
        //destructor

    protected:
        binaryTreeNode<elemType> *root;

    private:
        void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
        binaryTreeNode<elemType>* otherTreeRoot);
        //Makes a copy of the binary tree to which
        //otherTreeRoot points. The pointer copiedTreeRoot
        //points to the root of the copied binary tree.
    
        void destroy(binaryTreeNode<elemType>* &p);
        //Function to destroy the binary tree to which p points.
        //Postcondition: p = NULL

        void inorder(binaryTreeNode<elemType> *p) const {
            if (p != NULL)
            {
                inorder(p->llink);
                cout << p->info << " ";
                inorder(p->rlink);
            }
        }
        //Function to do an inorder traversal of the binary
        //tree to which p points.

        void preorder(binaryTreeNode<elemType> *p) const {
            if (p != NULL)
            {
                cout << p->info << " ";
                preorder(p->llink);
                preorder(p->rlink);
            }
        }
        //Function to do a preorder traversal of the binary
        //tree to which p points.

        void postorder(binaryTreeNode<elemType> *p) const {
            if (p != NULL)
            {
                postorder(p->llink);
                postorder(p->rlink);
                cout << p->info << " ";
            }
        }
        //Function to do a postorder traversal of the binary
        //tree to which p points.

        int height(binaryTreeNode<elemType> *p) const {
            if (p == NULL)
                return 0;
            else
                return 1 + max(height(p->llink), height(p->rlink));
        }
        //Function to return the height of the binary tree
        //to which p points.

        int max(int x, int y) const{
            if (x >= y)
                return x;
            else
                return y;
        }
        //Returns the larger of x and y.

        int nodeCount(binaryTreeNode<elemType> *p) const;
        //Function to return the number of nodes in the binary
        //tree to which p points

        int leavesCount(binaryTreeNode<elemType> *p) const;
        //Function to return the number of leaves in the binary
        //tree to which p points

};
