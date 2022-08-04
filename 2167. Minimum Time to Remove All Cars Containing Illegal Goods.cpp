class Solution {
public:
    int minimumTime(string s) {
        // let i, j in [1, n], i<j.
        // c[i] = #1s in [1, i]
        // cost =  i + (n-j+1) + 2*(c[j-1]-c[i])
        //      => i-2c[i] - (j-1-2c[j-1]) + n
        // Let t[i] = i - 2c[i];
        //      => t[i] - t[j-1] + n
        // min(cost) = min(t[i]-t[j]) + n
        int n = s.size();
        vector<int> t(n+1);
        for (int i=0, c=0; i<s.size(); ++i) {
            c += s[i] == '1';
            t[i+1] = i+1 - 2*c;
        }
        int mx = t[n], ans = n;
        for (int i=n-1; i>=0; --i) {
            ans = min(ans, t[i]-mx+n);
            mx = max(mx, t[i]);
        }
        return ans;
    }
};
