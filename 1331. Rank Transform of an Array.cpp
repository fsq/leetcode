class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        auto a = arr;
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        
        vector<int> ans;
        for (auto x : arr) ans.push_back(lower_bound(a.begin(), a.end(), x) - a.begin() + 1);
        return ans;
    }
};