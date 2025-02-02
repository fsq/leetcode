class Solution {
public:
    int minOperations(vector<int>& a) {
        int ans = 0, cur = 0;
        for (auto x : a)
            if ((x ^ cur) == 0) {
                ++ans;
                cur ^= 1;
            }
        return ans;
    }
};