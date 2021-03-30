/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool ans = helper(root, INT_MIN+1, INT_MIN+1);
        return ans;
    }
    
    bool helper(TreeNode* root, int max, int min)
    {
        if(root == NULL)
        {
            return true;
        }
        if((max != INT_MIN+1 && root->val >= max) || (min != INT_MIN+1 && root->val <= min))
        {
            return false;
        }
        return helper(root->left, root->val, min) & helper(root->right, max, root->val);
    }
};