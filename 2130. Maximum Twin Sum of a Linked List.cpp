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
    int pairSum(ListNode* head) {
        vector<int> a;
        for (auto p=head; p; p=p->next) a.push_back(p->val);
        int ans = INT_MIN;
        for (int i=0; i<a.size()/2; ++i)
            ans = max(ans, a[i] + a[a.size()-1-i]);
        return ans;
    }
};