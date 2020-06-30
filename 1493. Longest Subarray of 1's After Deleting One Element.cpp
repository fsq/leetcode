class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int s1=0, s0=0, ans=0;
        for (auto x : a) {
            if (x==1) {
                ++s1, ++s0;
            } else {
                s1 = s0;
                s0 = 0;
            }
            ans = max(ans, max(s1, s0));
        }
        return min<int>(ans, a.size()-1);
    }
};