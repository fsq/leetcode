class Solution {
public:
    int maxScore(vector<int>& a) {
        sort(a.begin(), a.end(), std::greater<int>());
        long long cur = 0;
        int ans = 0;
        for (auto x : a) {
            cur += x;
            if (cur > 0) ++ans;
        }
        return ans;
    }
};