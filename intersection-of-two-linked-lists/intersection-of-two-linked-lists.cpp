/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        
        if(nodeA == NULL || nodeB == NULL)
        {
            return NULL;
        }
        while(nodeA != nodeB)
        {
            
            nodeA = nodeA->next;
            nodeB = nodeB->next;
            
            if(nodeA == nodeB)
            {
                return nodeA;
            }
            
            if(nodeA == NULL)
            {
                nodeA = headB;
            }
            if(nodeB == NULL)
            {
                nodeB = headA;
            }
        }
        return nodeA;
    }
};