class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        reverse(a.begin(), a.end());
        int n = a.size();
        vector<int> f(n, INT_MIN), s(n);
        f[0] = a[0];
        partial_sum(a.begin(), a.end(), s.begin());
        for (int i=1; i<n; ++i) {
            for (int j=1; j<=3 && i+1>=j; ++j) 
                f[i] = max(f[i], i<j ? s[i] : s[i]-f[i-j]);
        }
        int alice = f.back(), bob = s.back()-f.back();
        return alice==bob ? "Tie" : (alice>bob ? "Alice":"Bob");
    }
};