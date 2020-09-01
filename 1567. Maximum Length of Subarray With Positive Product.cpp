class Solution {
public:
    int getMaxLen(vector<int>& a) {
        int INF = 0x3f3f3f3f;
        vector<int> p = {-1, INF};
        int ans = 0, s = 0; // 0:>0, 1:<0
        for (int i=0; i<a.size(); ++i)
            if (a[i]==0) {
                p = {i, INF};
                s = 0;
            } else {
                if (a[i] < 0) s ^= 1;
                if (p[s] != INF)
                    ans = max(ans, i-p[s]);
                else
                    p[s] = i;
            }
        return ans;
    }
};