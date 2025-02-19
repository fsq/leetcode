class Solution {
public:
    int maximumProfit(vector<int>& a, vector<int>& b, int budget) {
        vector<int> f(budget+1);
        for (int i=0; i<a.size(); ++i) {
            int cost = a[i], gain = b[i] - a[i];
            for (int j=budget; j>=a[i]; --j)
                f[j] = max(f[j], f[j-cost] + gain);
        }
        return ranges::max(f);
    }
};