class Solution {
public:
    long long countExcellentPairs(vector<int>& nm, int k) {
        unordered_set<int> a(nm.begin(), nm.end());
        vector<int> b(33);
        for (auto x : a) {
            ++b[__builtin_popcount(x)];
        }
        for (int i=b.size()-2; i>=0; --i) { 
            b[i] += b[i+1];
        }
        long long ans = 0;
        for (auto x : a) {
            int c = __builtin_popcount(x);
            if (k-c>=32) continue;
            ans += b[max(k-c, 0)];
        }
        return ans;
    }
};