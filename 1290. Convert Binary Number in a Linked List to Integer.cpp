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
    int getDecimalValue(ListNode* head) {
        int x = 0;
        for (auto p=head; p; p=p->next) {
            x = (x << 1) | p->val;
        }
        return x;
    }
};
