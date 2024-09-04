class Solution {
public:
    int minimumSum(vector<int>& a) {
        int ans = INT_MAX;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                for (int k=j+1; k<a.size(); ++k)
                    if (a[i]<a[j] && a[j]>a[k])
                        ans = min(ans, a[i]+a[j]+a[k]);
        return ans == INT_MAX ? -1 : ans;
    }
};