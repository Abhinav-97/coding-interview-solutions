/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        
        controlledInorder(root);
    }
    
    int next() {
        TreeNode* topVal = st.top();
        st.pop();
        TreeNode* curr = topVal->right;
        controlledInorder(curr);
        return topVal->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    
    stack<TreeNode*> st;
    
    void controlledInorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
    
    
};
​
