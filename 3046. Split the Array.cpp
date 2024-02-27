class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> f;
        for (auto x : nums)
            if (++f[x] > 2) return false;
        return true;
    }
};