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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        for (auto p=head; p; p=p->next) ++n;
        if (n==1) return nullptr;
        n = n/2-1;
        auto p = head;
        for (p=head; n; p=p->next, --n);
        auto t = p->next;
        p->next = t->next;
        delete t;
        return head;
    }
};