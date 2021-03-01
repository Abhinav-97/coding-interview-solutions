/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int helper(Node* root, int &ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        int maxDepth = 0;
        for(int i=0;i<root->children.size();i++)
        {
            int dpt = helper(root->children[i], ans);
            maxDepth = max(maxDepth, dpt);
        }
        ans = max(ans, maxDepth+1);
        return maxDepth+1;
    }
    int maxDepth(Node* root) {
        if(root == NULL)
        {
            return 0;
        }
        int ans=-1;
        helper(root, ans);
        return ans;
    }
};