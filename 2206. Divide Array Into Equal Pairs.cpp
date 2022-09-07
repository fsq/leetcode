class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x : nums) ++m[x];
        for (auto& pr : m)
            if (pr.second & 1)
                return false;
        return true;
    }
};