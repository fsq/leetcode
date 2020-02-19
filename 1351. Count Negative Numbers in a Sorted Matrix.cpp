class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int ans = 0;
        for (int j=a[0].size()-1,i=0; i<a.size(); ++i) {
            while (j>=0 && a[i][j]<0) --j;
            ans += a[0].size() - j - 1;
        }
        return ans;
    }
};