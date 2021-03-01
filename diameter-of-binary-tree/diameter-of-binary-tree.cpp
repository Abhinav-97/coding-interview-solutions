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
    int depthOfTree(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftDepth = depthOfTree(root->left) + 1;
        int rightDepth = depthOfTree(root->right) + 1;
        
        return max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int leftHeight = depthOfTree(root->left);
        int rightHeight = depthOfTree(root->right);
        
        return max(diameterOfBinaryTree(root->left), max(diameterOfBinaryTree(root->right), leftHeight+rightHeight));
    }
};