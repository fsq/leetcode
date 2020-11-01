class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& a) {
        set<int> s;
        for (auto& pr : a) s.insert(pr[0]);
        
        int ans = 0;
        for (auto it=s.begin(); next(it)!=s.end(); ++it)
            ans = max(ans, *next(it) - *it);
        return ans;
    }
};