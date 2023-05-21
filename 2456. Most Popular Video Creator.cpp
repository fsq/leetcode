class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> tv;
        unordered_map<string, set<pair<int,string>>> m;

        long long mxv = 0;
        for (int i=0; i<ids.size(); ++i) {
            mxv = max(mxv, tv[creators[i]] += views[i]);
            m[creators[i]].insert({-views[i], ids[i]});
        }

        vector<vector<string>> ans;
        for (auto& pr : tv)
            if (pr.second == mxv) {
                auto& name = pr.first;
                ans.push_back({name, m[name].begin()->second});
            }
        return ans;
    }
};