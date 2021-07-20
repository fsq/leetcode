class Solution {
public:
    int minPairSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = -1;
        for (int i=0, j=a.size()-1; i<j; ++i, --j)
            ans = max(ans, a[i]+a[j]);
        return ans;
    }
};