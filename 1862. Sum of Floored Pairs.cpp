class Solution {
public:
    int sumOfFlooredPairs(vector<int>& a) {
        vector<long long> s(100001);
        long long ans=0, tot=0;
        for (auto x : a) {
            tot += x;
            ++s[x];
        }
        for (int i=1; i<=100000; ++i)
            s[i] += s[i-1];
        ans = s[1] * s[1] + s[1] * (tot - s[1]);
        for (int i=2; i<=100000; ++i) {
            long long cur = s[i] - s[i-1];
            if (!cur) continue;
            ans += cur * cur;
            ans += (s[min(i+i-1, 100000)] - s[i]) * cur;
            for (int j=2; i*j<=100000; ++j) {
                ans += cur * j * 
                    (s[min(i*(j+1)-1, 100000)] - s[i*j-1]);
            }
        }
        return ans % 1000000007;
    }
};