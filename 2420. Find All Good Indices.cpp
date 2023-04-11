class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n = a.size();
        vector<int> l(n, 1), r(n, 1);
        for (int i=1; i<n; ++i) {
            l[i] = (a[i-1]>=a[i]) ? l[i-1]+1 : 1;
            r[n-i-1] = (a[n-i-1]<=a[n-i]) ? r[n-i]+1 : 1;
        }
        vector<int> ans;
        for (int i=k; i<n-k; ++i)
            if (l[i-1]>=k && r[i+1]>=k)
                ans.push_back(i);
        return ans;
    }
};