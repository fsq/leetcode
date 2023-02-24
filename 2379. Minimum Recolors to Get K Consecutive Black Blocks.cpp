class Solution {
public:
    int minimumRecolors(string a, int k) {
        int c = 0;
        for (int i=0; i<k; ++i) c += a[i]=='B';
        int ans = k - c;
        for (int i=k; i<a.size(); ++i) {
            c += a[i]=='B';
            c -= a[i-k]=='B';
            ans = min(ans, k-c);
            if (ans == 0) return 0;
        }
        return ans;
    }
};