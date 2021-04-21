class Solution {
public:
    
    int f[8][1<<15];
    
    int dp(vector<int>& a, int pr, int msk) {
        if (pr==0) return 0;
        if (f[pr][msk]) return f[pr][msk];
        int& ans = f[pr][msk];
        
        for (int i=0; i<a.size(); ++i)
            if ((1<<i) & msk)
                for (int j=i+1; j<a.size(); ++j)
                    if ((1<<j) & msk) {
                        int mt = msk ^ (1<<i) ^ (1<<j);
                        ans = max(ans, gcd(a[i], a[j])*pr + dp(a, pr-1, mt));
                    }
        return ans;
    }
    
    int maxScore(vector<int>& a) {
        return dp(a, a.size()/2, (1<<a.size())-1);
    }
};