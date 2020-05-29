class Solution {
public:
    int maxProfitAssignment(vector<int>& df, vector<int>& pf, vector<int>& wk) {
        vector<pair<int,int>> jb;
        for (int i=0; i<df.size(); ++i) 
            jb.push_back({df[i], pf[i]});
        sort(jb.begin(), jb.end());
        for (int i=1; i<jb.size(); ++i)
            jb[i].second = max(jb[i].second, jb[i-1].second);
        sort(wk.begin(), wk.end());
        int ans = 0;
        int i = 0;
        for (auto x : wk) {
            while (i<jb.size() && jb[i].first<=x) ++i;
            if (i>0)
                ans += jb[i-1].second;
        }
        return ans;
    }
};