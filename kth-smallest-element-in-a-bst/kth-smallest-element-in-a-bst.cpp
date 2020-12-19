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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while(!st.empty() || curr != NULL)
        {
            while(curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* topVal = st.top();
            if(k-1 == 0)
            {
                return topVal->val;
            }
            k--;
            st.pop();
            curr = topVal->right;
        }
        return 0;
    }
    
    void getInorder(TreeNode* root, vector<int> &inorder)
    {
        if(root == NULL)
        {
            return;
        }
        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
};
