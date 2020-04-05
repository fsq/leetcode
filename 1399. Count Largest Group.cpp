class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> s(37);
        int mx = 0, ans = 0;
        for (int i=1; i<=n; ++i) {
            int t = 0;
            for (int j=i; j; j/=10) t += j % 10;
            ++s[t];
            if (s[t] > mx) {
                mx = s[t];
                ans = 1;
            } else if (s[t] == mx) 
                ++ans;
        }
        return ans;
    }
};