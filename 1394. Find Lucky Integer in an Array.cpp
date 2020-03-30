class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto x : arr) ++m[x];
        int ans = -1;
        for (auto& pr : m)
            if (pr.first == pr.second)
                ans = max(ans, pr.first);
        return ans;
    }
};