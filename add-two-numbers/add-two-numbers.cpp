/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ans = new ListNode(0);
        ListNode* temp = ans;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {   
            int x=0,y=0;
            if(l1 != NULL)
            {
                x = l1->val;
            }
            if(l2 != NULL)
            {
                y = l2->val;
            }
            int newSum = x + y + carry;
            int newDigit = newSum%10;
            carry = newSum/10;
            
            temp->next = new ListNode(newDigit);
            if(l1 != NULL)
            {
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(carry)
        {
            temp->next = new ListNode(carry);
            
        }
        return ans->next;
        
    }
};
