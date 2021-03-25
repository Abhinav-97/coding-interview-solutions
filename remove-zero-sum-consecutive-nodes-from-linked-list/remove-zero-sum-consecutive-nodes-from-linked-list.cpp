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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sumMap;
        bool cont = true;
        while(cont)
        {
            ListNode* temp = head;
            cont = false;
            int sum = 0;
            while(temp != NULL)
            {
                sum += temp->val;
                if(sumMap.find(sum) != sumMap.end())
                {
                    ListNode* tail = sumMap[sum];
                    tail->next = temp->next;
                    sumMap.clear();
                    sum = 0;
                    cont = true;
                    break;
                }
                else if(sum == 0)
                {
                    head = temp->next;
                    sum = 0;
                    sumMap.clear();
                    cont = true;
                    break;
                }
                else{
                    sumMap[sum] = temp;
                    temp = temp->next;
                }
            }
        }
        return head;
    }
};