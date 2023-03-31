class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto& pr : intervals) {
            ++m[pr[0]];
            --m[pr[1]+1];
        }
        int ans = 0, c = 0;
        for (auto& pr : m) {
            c += pr.second;
            ans = max(ans, c);
        }
        return ans;
    }
};