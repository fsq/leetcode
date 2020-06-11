class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int, int> c1;
        for (auto x : a) for (auto y : b) ++c1[x+y];
        int ans = 0;
        for (auto x : c) for (auto y : d) ans += c1[-x-y];
        return ans;
    }
};