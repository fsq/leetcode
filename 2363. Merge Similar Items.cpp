class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& a, vector<vector<int>>& b) {
        unordered_map<int, int> m;
        for (auto& pr : a) m[pr[0]] = pr[1];
        for (auto& pr : b) m[pr[0]] += pr[1];
        vector<vector<int>> ans;
        for (auto& pr : m) ans.push_back({pr.first, pr.second});
        sort(ans.begin(), ans.end());
        return ans;
    }
};