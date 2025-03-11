class Solution {
public:
    long long singleDivisorTriplet(vector<int>& nums) {
        vector<long long> cnt(101);
        for (auto x : nums) ++cnt[x];
        long long ans = 0;
        // i, j, k
        for (int i=1; i<=100; ++i)
            for (int j=i+1; j<=100; ++j)
                for (int k=j+1; k<=100; ++k) {
                    int sum = i + j + k;
                    int d = (sum%i==0) + (sum%j==0) + (sum%k==0);
                    if (d == 1) {
                        ans += cnt[i] * cnt[j] * cnt[k] * 6;
                    }
                }
        // i, i, j
        for (int i=1; i<=100; ++i)
            if (cnt[i] > 1)
                for (int j=1; j<=100; ++j)
                    if (j != i) {
                        int sum = i + i + j;
                        if (sum%i!=0 && sum%j==0) {
                            ans += (cnt[i] * (cnt[i]-1) / 2) * cnt[j] * 6;
                        }
                    }
        return ans;
    }
};