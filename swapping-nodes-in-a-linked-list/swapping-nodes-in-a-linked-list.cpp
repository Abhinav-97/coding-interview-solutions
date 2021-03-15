/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* node1 = head;
        int cnt = 0;
        
        while(cnt < k-1)
        {
            cnt++;
            node1 = node1->next;
        }
        ListNode* temp = node1;
        ListNode* node2 = head;
        while(temp != NULL && temp->next != NULL)
        {
            node2 = node2->next;
            temp = temp->next;
        }
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
        
        
        return ans->next;
    }
};