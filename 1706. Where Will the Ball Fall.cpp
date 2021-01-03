class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        vector<int> ans;
        int n = a.size(), m = a[0].size();
        for (int i=0; i<m; ++i) {
            int x = i, y = 0;
            while (y < n) {
                if (a[y][x]==1) {
                    if (x+1==m || a[y][x+1]==-1) break;
                    ++x, ++y;
                } else {
                    if (x==0 || a[y][x-1]==1) break;
                    --x, ++y;
                }
            }
            ans.push_back(y==n ? x : -1);
        }
        return ans;
    }
};