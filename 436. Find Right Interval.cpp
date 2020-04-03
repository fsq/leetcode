class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intv) {
        vector<pair<int, int>> a;
        for (int i=0; i<intv.size(); ++i)
            a.push_back({intv[i][0], i});
        
        sort(a.begin(), a.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.first<b.first || a.first==b.first && a.second<b.second;
        });
        vector<int> ans;
        for (int i=0; i<intv.size(); ++i) {
            auto it = lower_bound(a.begin(), a.end(), pair<int,int>{intv[i][1],INT_MIN});
            ans.push_back(it==a.end() ? -1 : it->second);
        }
        return ans;
    }
};