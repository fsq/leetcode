class Solution {
public:
    
    bool ok(const string& a, const string& b) {
        int i = 0;
        for (; i<a.size() && a[i]==b[i]; ++i);
        if (i==a.size()) return true;
        for (; i<a.size() && a[i]==b[i+1]; ++i);
        return i==a.size();
    }
    
    int longestStrChain(vector<string>& a) {
        sort(a.begin(), a.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = a.size(), ans = 0;
        vector<int> f(n);
        f[n-1] = 1;
        for (int j,i=n-2; i>=0; --i) {
            f[i] = 1;
            j = i+1;
            while (j<n && a[j].size()<a[i].size()+1) ++j;
            while (j<n && a[j].size()==a[i].size()+1) {
                if (ok(a[i], a[j]))
                    f[i] = max(f[i], f[j]+1);
                ++j;
            }
            ans = max(f[i], ans);
        }
        return ans;
    }
};