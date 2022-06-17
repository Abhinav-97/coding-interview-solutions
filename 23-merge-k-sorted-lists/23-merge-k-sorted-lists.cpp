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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size() == 0 || lists[0] == NULL)
        // {
        //     return NULL;
        // }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i] != NULL)
            {
                pq.push(make_pair(lists[i]->val, lists[i]));
            }
        }
        while(!pq.empty())
        {
            pair<int, ListNode*> pr = pq.top();
            pq.pop();
            
            ans->next = new ListNode(pr.first);
            ans = ans->next;
            ListNode* newNode = pr.second;
            if(newNode->next != NULL)
            {
                pq.push(make_pair(newNode->next->val, newNode->next));
            }
        }
        return dummy->next;
    }
};