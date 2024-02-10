class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> a(n), ans;
        int p = 0;
        for (auto& pr : q) {
            int i = pr[0], c = pr[1];
            int before = 0, after = 0;
            if (i>0 && a[i]==a[i-1] && a[i]!=0) ++before;
            if (i+1<n && a[i]==a[i+1] && a[i]!=0) ++before;
            a[i] = c;
            if (i>0 && a[i]==a[i-1] && a[i]!=0) ++after;
            if (i+1<n && a[i]==a[i+1] && a[i]!=0) ++after;
            p += after - before;
            ans.push_back(p);
        }
        return ans;
    }
};