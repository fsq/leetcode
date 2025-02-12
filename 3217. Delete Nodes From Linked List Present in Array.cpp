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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        auto f = new ListNode();
        f->next = head;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto p=f; p && p->next; ) {
            if (st.count(p->next->val)) {
                auto t = p->next;
                p->next = t->next;
            } else {
                p=p->next;
            }
        }
        return f->next;
    }
};