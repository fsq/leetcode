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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> stk;
        for (int i=0; head; head=head->next, ++i) {
            while (stk.size() && head->val>stk.top().first) {
                ans[stk.top().second] = head->val;
                stk.pop();
            }
            ans.push_back(0);
            stk.push({head->val, i});
        }
        return ans;
    }
};