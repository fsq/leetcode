class Solution {
public:
    int maximumStrongPairXor(vector<int>& a) {
        int ans = 0;
        for (auto x : a)
            for (auto y : a)
                if (abs(x-y) <= min(x, y)) {
                    ans = max(ans, x ^ y);
                }
        return ans;
    }
};