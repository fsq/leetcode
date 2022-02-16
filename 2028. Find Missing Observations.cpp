class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int C = accumulate(rolls.begin(), rolls.end(), 0);
        int S = mean * (n+rolls.size()) - C;
        if (S >= n && S <= 6*n) {
            int a = (S-n) / 5;
            vector<int> ans(a, 6);
            ans.insert(ans.end(), n-a, 1);
            S -= 6*a + n-a;
            if (S > 0) {
                ans[a] += S;
            }
            return ans;
        } else {
            return {};
        }
    }
};