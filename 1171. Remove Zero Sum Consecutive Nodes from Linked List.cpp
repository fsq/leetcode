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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, vector<int>> pos;
        vector<pair<int,int>> seg;
        pos[0] = {-1};
        int n=0, s=0;
        for (auto p=head; p; p=p->next, ++n) {
            s += p->val;
            for (auto j : pos[s])
                seg.push_back({j+1, n});
            pos[s].push_back(n);
        }
        sort(seg.begin(), seg.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.first < b.first || a.first==b.first && a.second>b.second; 
        });
        
        vector<int> vis(n);
        for (int right=-1, i=0; i<seg.size();) {
            for (int j=seg[i].first; j<=seg[i].second; ++j)
                vis[j] = true;
            right = seg[i].second;
            while (i<seg.size() && seg[i].first<=right) ++i;
        }
        
        ListNode* fst = new ListNode(0), *now = fst;
        int i = 0;
        for (auto p=head; p; p=p->next, ++i) 
            if (!vis[i]) {
                now->next = new ListNode(p->val);
                now = now->next;
            }
        return fst->next;
    }
};