class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums) {
            int sq = sqrt(x);
            if (sq*sq==x) continue;
            int cnt = 0;
            for (int i=2; i<=sq; ++i) 
                if (x % i==0) {
                    if (cnt>1) goto last;
                    cnt = 1 + x + i + x/i;
                }
            ans += cnt;
            last:
            continue;
        }
        return ans;
    }
};