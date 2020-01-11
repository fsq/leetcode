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
    ListNode* swapPairs(ListNode* head) {
        auto* h = new ListNode(0);
        h->next = head;
        for (auto p=h; p->next && p->next->next; p=p->next->next) {
            auto t = p->next;
            p->next = t->next;
            t->next = t->next->next;
            p->next->next = t;
        }
        auto ans = h->next;
        delete h;
        return ans;
    }
};