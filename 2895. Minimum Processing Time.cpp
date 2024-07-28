class Solution {
public:
    int minProcessingTime(vector<int>& a, vector<int>& b) {
        sort(b.rbegin(), b.rend());
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int cur = 0;
            for (int j=i*4; j<(i+1)*4; ++j) {
                cur = max(cur, a[i] + b[j]);
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};