class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0, pre = 0;
        for (int i=0; i<brackets.size() && income > pre; ++i) {
            ans += (min(income, brackets[i][0]) - pre) * brackets[i][1] / 100.0;
            pre = brackets[i][0];
        }
        return ans;
    }
};