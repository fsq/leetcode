class Solution {
public:
    int dietPlanPerformance(vector<int>& a, int k, int lower, int upper) {
        int ans = 0;
        for (int s=0, i=0; i<a.size(); ++i) {
            s += a[i];
            if (i >= k)
                s -= a[i-k];
            if (i >= k-1) {
                if (s > upper) ++ans;
                if (s < lower) --ans;
            }
        }
        return ans;
    }
};