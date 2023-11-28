class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int mx_score = 0, ans = INT_MAX;
        for (auto d : divisors) {
            int score = 0;
            for (auto x : nums) if (x % d == 0) ++score;
            if (score > mx_score || score==mx_score && d < ans) {
                ans = d;
                mx_score = score;
            }
        }
        return ans;
    }
};