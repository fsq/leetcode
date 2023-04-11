class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int mx = 0, cur = 0, ans = 0;
        for (auto x : a)
            if (x > mx) {
                mx = x;
                cur = ans = 1;
            } else if (x == mx) {
                ++cur;
                ans = max(ans, cur);
            } else 
                cur = 0;
        return ans;
    }
};