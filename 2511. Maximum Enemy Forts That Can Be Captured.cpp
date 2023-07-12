class Solution {
public:
    int captureForts(vector<int>& a) {
        int ans = 0, i = 0, j = 0;
        while (i<a.size()) {
            while (i<a.size() && a[i] != 1) ++i;
            if (i==a.size()) break;
            for (j=i-1; j>=0 && a[j]==0; --j);
            if (j>=0 && a[j]==-1) ans = max(ans, i-j-1);
            for (j=i+1; j<a.size() && a[j]==0; ++j);
            if (j<a.size() && a[j]==-1) ans = max(ans, j-i-1);
            i = j;
        }
        return ans;
    }
};