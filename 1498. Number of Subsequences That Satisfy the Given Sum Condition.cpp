class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numSubseq(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        vector<int> pow(a.size());
        pow[0] = 1;
        int ans = 0;
        for (int i=1; i<pow.size(); ++i)
            pow[i] = (pow[i-1]<<1) % M;
        for (int l=0, r=a.size()-1; l<=r; ++l) {
            while (l<r && a[l]+a[r]>target) --r;
            if (a[l]+a[r] <= target)
                ans = (ans + pow[r - l]) % M;
        }
        return ans;
    }
};