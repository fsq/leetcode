class Solution {
public:
    long long countBadPairs(vector<int>& a) {
        unordered_map<int, int> m;
        long long ans = 0;
        for (int i=0; i<a.size(); ++i) {
            ans += i - m[i-a[i]];
            ++m[i-a[i]];
        }
        return ans;
    }
};