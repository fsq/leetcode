class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numSub(string s) {
        long long ans = 0;
        int l = 0;
        for (auto x : s)
            if (x=='1') {
                ++l;
                ans = (ans + l) % M;
            } else {
                l = 0;
            }
        return ans;
    }
};