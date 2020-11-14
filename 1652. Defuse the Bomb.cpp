class Solution {
public:
    vector<int> decrypt(vector<int>& a, int k) {
        vector<int> ans(a.size());
        if (k==0) return ans;
        int d = k > 0 ? 1 : -1;        
        for (int i=0; i<a.size(); ++i) {
            int x = i;
            for (int j=1; j<=abs(k); ++j) {
                x = (x + d + a.size()) % a.size();
                ans[i] += a[x];
            }
        }
        return ans;
    }
};