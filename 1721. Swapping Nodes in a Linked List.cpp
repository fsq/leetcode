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
        auto* fst = new ListNode(0, head);
        int n = 0;
        for (auto p=head; p; p=p->next) ++n;
        if (k > n-k+1) k = n-k+1;
        if (k==n-k+1) return head;
        
        ListNode *x=head, *y=head;
        
        auto p = fst;
        for (int i=0; i<n-k; ++i, p=p->next)
            if (i==k-1) 
                x = p;
        y = p;
        if (x->next == y) {
            auto t = y->next;
            y->next = y->next->next;
            t->next = y;
            x->next = t;
        } else {
            swap(x->next->next, y->next->next);
            swap(x->next, y->next);
        }
        return fst->next;
    }
};
