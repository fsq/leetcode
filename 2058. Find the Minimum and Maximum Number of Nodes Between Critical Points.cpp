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
    
    bool local(int x, int y, int z) {
        return y>x && y>z || y<x && y<z;
    }
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev=-1, nxv=-1, firsti=-1, prei=-1;
        vector<int> ans = {INT_MAX, -1};
        int ind = 0;
        for (auto p=head; p; p=p->next, ++ind) {
            if (prev!=-1 && p->next && local(prev, p->val, p->next->val)) {
                if (firsti == -1) {
                    firsti = ind;
                } else {
                    ans[0] = min(ans[0], ind - prei);
                    ans[1] = ind - firsti;
                }
                prei = ind;
            }
            prev = p->val;
        }
        if (ans[0] == INT_MAX) ans[0] = -1;
        return ans;
    }
};