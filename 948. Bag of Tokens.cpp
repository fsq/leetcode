class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int power) {
        sort(a.begin(), a.end());
        int n = a.size();
        int p = 0, ans = 0;
        for (int i=0, j=n-1; i<=j; )
            if (power>=a[i]) {
                power -= a[i++];
                ++p;
            } else if (p && i<j) {
                power += a[j--];
                --p;
            } else break;
        return p;
    }
};