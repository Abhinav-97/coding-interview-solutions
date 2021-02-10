/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<int, Node*> idxMap;
        map<Node*, Node*> valMap;
        Node*temp = head;
        int idx = 0;
        while(temp != NULL)
        {
            Node* newNode = new Node(temp->val);
        
            valMap[temp] = newNode;
            
            temp = temp->next;
        }
        Node* ans = new Node(0);
        Node* dummy = ans;
        idx = 0;
        while(head != NULL)
        {
            dummy->next = valMap[head];
            dummy = dummy->next;
            if(head->random)
            {
                dummy->random = valMap[head->random];
            }
            head = head->next;
        }
        return ans->next;
    }
};