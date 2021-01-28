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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = constructTree(preorder);
        return root;
    }
    TreeNode* constructTree(vector<int> preorder)
    {
        if(preorder.empty())
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> leftNodes;
        vector<int> rightNodes;
        for(int i=1;i<preorder.size();i++)
        {
            if(preorder[i] < preorder[0])
            {
                leftNodes.push_back(preorder[i]);
            }
            else{
                rightNodes.push_back(preorder[i]);
            }
        }
        root->left = constructTree(leftNodes);
        root->right = constructTree(rightNodes);
        
        return root;
    }
};