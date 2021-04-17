class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int ans = a[k];
        for (int l=k, r=k, mn=a[k]; l>0 || r+1<a.size(); ) {
            if (l==0)
                ++r;
            else if (r+1==a.size())
                --l;
            else if (a[l-1] > a[r+1])
                --l;
            else
                ++r;
            mn = min(mn, min(a[l], a[r]));
            ans = max(ans, mn * (r-l+1));
        }
        return ans;
    }
};