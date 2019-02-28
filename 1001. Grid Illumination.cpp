class Solution {
public:
    
    vector<int> dx = {-1,-1,0,1,1,1,0,-1,0};
    vector<int> dy = {0,1,1,1,0,-1,-1,-1,0};
    
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& qr) {
        unordered_map<int, int> row, col, lf, rt;
        unordered_map<int, unordered_set<int>> a;

        for (auto& lamp : lamps) {
            a[lamp[0]].insert(lamp[1]);
            ++row[lamp[0]];
            ++col[lamp[1]];
            ++lf[lamp[0]-lamp[1]+n-1];
            ++rt[lamp[0]+lamp[1]];
        }

        vector<int> ans;
        for (auto& q : qr) {
            int x=q[0], y=q[1];
            ans.push_back(row[x] || col[y] || lf[x-y+n-1] || rt[x+y]);
            for (int dir=0; dir<9; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (a.count(tx) && a[tx].count(ty)) {
                    a[tx].erase(ty);
                    --row[tx];
                    --col[ty];
                    --lf[tx-ty+n-1];
                    --rt[tx+ty];
                }
            }
        }
            return ans;
    }
};