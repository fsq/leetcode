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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans = nullptr, *tail = nullptr ;
        for (auto p=head; p; )
            if (p->val == 0)
                p = p->next;
            else {
                if (!ans) {
                    ans = tail = p;
                } else {
                    tail->next = p;
                    tail = p;            
                }
                p = p->next;
                while (p && p->val != 0) {
                    tail->val += p->val;
                    p = p->next;
                }
            }
        tail->next = nullptr;
        return ans;
    }
};