class Solution {
public:
    int jobScheduling(vector<int>& l, vector<int>& r, vector<int>& profit) {
        unordered_map<int, vector<int>> ed;
        for (int i=0; i<l.size(); ++i)
            ed[r[i]].push_back(i);
        
        set<int> s(l.begin(), l.end());
        for (auto x : r) s.insert(x);
        
        unordered_map<int, int> f;
        int ans = 0;
        for (auto it=s.begin(); it!=s.end(); ++it) {
            int r = *it;
            int& x = f[r];
            x = it==s.begin() ? 0 : f[*prev(it)];
            for (auto ind : ed[r]) {
                int beg = l[ind];
                x = max(x, f[beg] + profit[ind]);
            }
            ans = max(ans, x);
        }
        return ans;
    }
};