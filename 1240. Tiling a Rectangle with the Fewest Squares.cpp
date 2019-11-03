class Solution {
public:
    int ans = INT_MAX, n, m;
    
    int find_next(vector<vector<int>>& a, int x, int y) {
        int r = m;
        for (auto& s : a) 
            if (s[0]<=x && x<s[0]+s[2] && y<=s[1])
                r = min(r, s[1]);
        return r;
    }
    
    pair<int, int> find_space(vector<vector<int>>& a, int x, int y) {
        while (x < n) {
            if (y==m) {
                ++x;
                y = 0;
                continue;
            }
            bool jumped = false;
            for (auto& s : a)
                if (s[0]<=x && x<s[0]+s[2] && y==s[1]) {
                    y += s[2];
                    jumped = true;
                    break;
                }
            if (!jumped) break;
        }
        return {x, y};
    }
    
    void dfs(vector<vector<int>>& a, int x, int y) {
        if (x==n) {
            ans = min<int>(ans, a.size());
        } else {
            if (a.size() >= ans) return;
            for (int r=min(find_next(a, x, y) - y, n-x); r; --r) {
                a.push_back({x, y, r});
                int tx, ty;
                tie(tx, ty) = find_space(a, x, y+r);
                dfs(a, tx, ty);
                a.pop_back();
            }
        }
    }
    
    int tilingRectangle(int n_, int m_) {
        n = n_;
        m = m_;
        vector<vector<int>> a;
        dfs(a, 0, 0);
        return ans;
    }
};