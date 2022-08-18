class Solution {
public:
    long long countPairs(vector<int>& a, int k) {
        unordered_map<int, int> m;
        for (int i=1; i*i<=k; ++i)
            if (k % i == 0) {
                m[k/i] = 0;
                m[i] = 0;
            }
        
        long long ans = 0;
        for (int i=0; i<a.size(); ++i) {
            if (a[i] % k == 0) {
                ans += i;
            } else {
                ans += m[k / gcd(a[i], k)];
            }
            for (auto& pr : m)
                if (a[i] % pr.first == 0)
                    ++pr.second;
        }
        return ans;
    }
};