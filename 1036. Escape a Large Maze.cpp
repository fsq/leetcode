class Solution {
public:
    
    bool meet = false;
    int nb;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    const int N = 1e6;
    
    bool surround(const vector<int>& s, const vector<int>& dst, set<pair<int,int>>& a) {
        vector<pair<int,int>> q;
        q.push_back({s[0], s[1]});
        int x, y, i;
        for (x,y,i=0; i<q.size() && i<nb*nb; ++i) {
            tie(x, y) = q[i];
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];   
                if (tx>=0 && tx<N && ty>=0 && ty<N && !a.count({tx, ty})) {
                    if (dst == vector<int>{tx, ty}) {
                        meet = true;
                        return false;
                    }
                    q.push_back({tx, ty});
                    a.insert({tx, ty});
                }
            }
        }
        return i < nb*nb; 
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>> b;
        for (auto& x : blocked) b.insert({x[0], x[1]});
        nb = blocked.size();
        if (surround(source, target, b))
            return false;
        if (meet) return true;
        return !surround(target, source, b);
    }
};