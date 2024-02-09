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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (auto p=head; p->next; p=p->next->next) {
            int x = p->val, y = p->next->val;
            ListNode* g = new ListNode(gcd(x, y), p->next);
            p->next = g;
        }
        return head;
    }
};