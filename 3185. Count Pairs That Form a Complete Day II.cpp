class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        unordered_map<int, int> m;
        long long ans = 0;
        for (auto x : a) {
            ans += m[(24 - x%24) % 24];
            ++m[x%24];
        }
        return ans;
    }
};