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
    ListNode* removeNodes(ListNode* x) {
        if (!x) return nullptr;
        auto nxt = removeNodes(x->next);
        if (!nxt) {
            return x;
        } else {
            auto mx = nxt->val;
            if (x->val < mx)
                return nxt;
            else {
                x->next = nxt;
                return x;
            }
        }
    }
};