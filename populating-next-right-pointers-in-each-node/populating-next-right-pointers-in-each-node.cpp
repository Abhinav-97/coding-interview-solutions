/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        helper(root, NULL); 
        return root;
    }
    
    Node* helper(Node* root, Node* rightPtr)
    {
        if(root == NULL)
        {
            return NULL;
        }
        root->next = rightPtr;
        if(root->left)
        {
            root->left = helper(root->left, root->right);
        }
        if(rightPtr != NULL)
        {
            root->right = helper(root->right, rightPtr->left);
        }
        else{
            root->right = helper(root->right, rightPtr);
        }
        return root;
    }
};