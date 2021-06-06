class Solution {
public:
    int maxFrequency(vector<int>& a, int k) {
        int ans = 0;
        sort(a.begin(), a.end());
        for (int s=0, l=0, r=0; l<a.size(); ++l) {
            while (r+1<a.size() && s+(long long)(a[r+1]-a[r])*(r-l+1)<=k) {
                s += (a[r+1] - a[r]) * (r-l+1);
                ++r;
            }
            ans = max(ans, r-l+1);
            s -= a[r] - a[l];
        }
        return ans;
    }
};