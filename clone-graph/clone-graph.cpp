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
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        Node* newNode = new Node(node->val, {});
        
        mp[node] = newNode;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            
            vector<Node*> vec = curr->neighbors;
            for(int i=0;i<vec.size();i++)
            {
                if(mp.find(vec[i]) == mp.end())
                {
                    Node* neighbourNode = new Node(vec[i]->val,{});
                    mp[vec[i]] = neighbourNode;
                    q.push(vec[i]);
                }
                
                mp[curr]->neighbors.push_back(mp[vec[i]]);
            }
        }
        return newNode;
    }
};
