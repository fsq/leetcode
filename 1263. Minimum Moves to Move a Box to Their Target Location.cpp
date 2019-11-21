#define FOR(i, n) for (int i=0; i<n; ++i)
class Solution {
public:
    using PII = pair<int,int>;
    
    int n, m;
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int encode(const PII& a, const PII& b) {
        return a.first*1000000 + a.second*10000 + b.first*100 + b.second;
    }
    
    void flood(vector<vector<char>>& map, const PII& box, PII man) {
        map[man.first][man.second] = 'S';
        FOR(dir, 4) {
            int tx=man.first+dx[dir], ty=man.second+dy[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<m && map[tx][ty]=='.' && PII{tx,ty}!=box)
                flood(map, box, {tx, ty});
        }
    }
    
    int minPushBox(vector<vector<char>>& a) {
        n = a.size(), m = a[0].size();
        PII tar, man, box;
        FOR(i, n) FOR(j, m) 
            if (a[i][j] == 'T')
                tar = {i, j}, a[i][j] = '.';
            else if (a[i][j] == 'B') 
                box = {i, j}, a[i][j] = '.';
            else if (a[i][j] == 'S')
                man = {i, j}, a[i][j] = '.';
        
        if (tar == box) return 0;
        
        unordered_set<int> vis;
        queue<pair<PII, PII>> q;
        q.push({box, man});
        vis.insert(encode(box, man));
        
        auto valid = [&](int x, int y) { return x>=0 && x<n && y>=0 && y<m && a[x][y]!='#'; };
        
        int ans = INT_MAX;
        for (int stp=1; !q.empty(); ++stp)
            for (auto sz=q.size(); sz; --sz) {
                PII box, man;
                tie(box, man) = q.front(); q.pop();
                auto reach = a;
                flood(reach, box, man);
                FOR(dir, 4) {
                    int tx=box.first+dx[dir], ty=box.second+dy[dir];
                    if (valid(tx, ty) && reach[tx][ty]=='S') {
                        int bx=box.first-dx[dir], by=box.second-dy[dir];
                        PII new_box{bx, by};
                        if (new_box == tar)
                            return stp;
                        else if (valid(bx, by)) {
                            int h = encode(new_box, box);
                            if (!vis.count(h)) {
                                q.push({move(new_box), box});
                                vis.insert(h);
                            }
                        }
                    }
                }
            }
            
        return -1;
    }
};