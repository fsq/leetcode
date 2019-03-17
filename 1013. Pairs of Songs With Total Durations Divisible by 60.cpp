class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& a) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int x : a) {
            x %= 60;
            ans += m[(60 - x) % 60];
            ++m[x];
        }
        return ans;
    }
};