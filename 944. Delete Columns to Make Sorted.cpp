class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        for (int j=0; j<m; ++j) {
            bool inc = true;
            for (int i=0; i+1<n; ++i)
                if (a[i+1][j]<a[i][j]) {
                    inc = false;
                    break;
                }
            ans += !inc;
        }
        return ans;
    }
};