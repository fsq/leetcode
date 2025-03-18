class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        unordered_map<int, unordered_set<int>> cnt;
        int ans = 0;
        for (auto pr :  students) {
            cnt[pr[1]].insert(pr[0]);
        }
        for (auto& pr : cnt)
            ans = max<int>(ans, pr.second.size());
        return ans;
    }
};