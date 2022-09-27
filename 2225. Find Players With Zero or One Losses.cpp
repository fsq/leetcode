class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> win, los;
        for (auto& pr : matches) {
            ++win[pr[0]];
            ++los[pr[1]];
        }
        vector<vector<int>> ans(2);
        for (auto& pr : win)
            if (los[pr.first] == 0)
                ans[0].push_back(pr.first);
        for (auto& pr : los)
            if (pr.second == 1)
                ans[1].push_back(pr.first);
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};