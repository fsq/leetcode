class Solution {
public:
    int numberOfPairs(vector<vector<int>>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a.size(); ++j) {
                if (i==j) continue;
                if (a[i][0]<=a[j][0] && a[i][1]>=a[j][1]) {
                    bool ok = true;
                    for (int k=0; k<a.size(); ++k)
                        if (k!=i && k!=j && a[k][0]>=a[i][0] && a[k][0]<=a[j][0] && a[k][1]<=a[i][1] && a[k][1]>=a[j][1]) {
                            ok = false;
                            break;
                        }
                    if (ok) ++ans;
                }
            }
        return ans;
    }
};