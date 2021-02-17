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
    TreeNode* convertBST(TreeNode* root) {
        int cumSum = 0;
        helper(root, cumSum); 
        return root; 
    }
    
    void helper(TreeNode* root, int &cumSum)
    {
        if(root == NULL)
        {
            return;
        }
        helper(root->right, cumSum);
        cumSum += root->val;
        root->val = cumSum;
        helper(root->left, cumSum);
    }
};