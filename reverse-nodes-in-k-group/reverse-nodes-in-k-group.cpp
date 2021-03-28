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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        while(curr != NULL)
        {
            curr = curr->next;
            len++;
        }
        ListNode* res;
        bool firstNode = true;
        ListNode* currHead = head;
        while(len >= k)
        {
            cout<<currHead->val<<endl;
            int cnt = 0;
            ListNode* prev = NULL;
            ListNode* curr = currHead;
            ListNode* temp;
            while(cnt < k)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                cnt++;
            }
            if(firstNode)
            {
                firstNode = false;
                dummy->next = prev;
            }
            else{
                head->next = prev;
                head = currHead;
            }
            currHead->next = curr;
            currHead = curr;
            len -= k;
        }
        return dummy->next;
    }
};