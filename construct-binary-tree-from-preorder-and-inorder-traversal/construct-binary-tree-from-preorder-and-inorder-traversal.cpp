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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int start = 0;
        int end = preorder.size()-1;
        TreeNode* root = helper(preorder, inorder, index, start, end);
        return root;
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end)
    {
        if(index == preorder.size())
        {
            return NULL;
        }
        if(start > end)
        {
            return NULL;
        }
        int preorderVal = preorder[index];
        TreeNode* root = new TreeNode(preorder[index]);
        int valIndex;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i] == preorderVal)
            {
                valIndex = i;
                break;
            }
        }
        index++;
        root->left = helper(preorder, inorder, index, start, valIndex-1);
        root->right = helper(preorder, inorder, index, valIndex+1, end);
        
        return root;
    }
};