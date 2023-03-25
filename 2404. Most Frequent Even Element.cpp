class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x : nums)
            if (!(x & 1))
                ++m[x];
        int mx = 0, ans = -1;
        for (auto& pr : m)
            if (pr.second > mx || pr.second==mx && pr.first<ans) {
                ans = pr.first;
                mx = pr.second;
            }
        return ans;
    }
};