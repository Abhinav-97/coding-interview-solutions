/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
​
class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        dfs(node, mp);
        return mp[node];
    }
    void dfs(Node* node, unordered_map<Node*, Node*> &mp)
    {
        if(node == NULL)
        {
            return;
        }
        if(mp[node] != NULL)
        {
            return;
        }
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        vector<Node*> vec = node->neighbors;
        for(int i=0;i<vec.size();i++)
        {
            if(mp.find(vec[i]) == mp.end())
            {
                dfs(vec[i], mp);
            }
            mp[node]->neighbors.push_back(mp[vec[i]]);
        }
    }
};
