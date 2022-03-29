class Solution {
public:
    int countMaxOrSubsets(vector<int>& a) {
        int mx=0, cnt=0, n=a.size();
        for (int i=1; i<(1<<n); ++i) {
            int s = 0;
            for (int j=0; j<n; ++j)
                if ((i>>j) & 1)
                    s |= a[j];
            if (s > mx) {
                mx = s;
                cnt = 1;
            } else if (s == mx)
                ++cnt;
        }
        return cnt;
    }
};