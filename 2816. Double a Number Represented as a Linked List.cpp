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

    ListNode* rev(ListNode* head) {
        ListNode *x=head, *y=head->next;
        x->next = nullptr;
        while (y) {
            auto t = y->next;
            y->next = x;
            x = y;
            y = t;
        }
        return x;
    }

    ListNode* doubleIt(ListNode* head) {
        head = rev(head);
        int cur = 0;
        for (auto x=head; x; x=x->next) {
            int s = x->val*2 + cur;
            cur = s / 10;
            x->val = s % 10;
        }
        head = rev(head);
        if (cur) {
            head = new ListNode(1, head);
        }
        return head;
    }
};