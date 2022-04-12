class Solution {
public:
    int ans = 0;
    
    vector<int> dx = {-1, -1, 0, 1, 1,  1,  0, -1};
    vector<int> dy = {0,   1, 1, 1, 0, -1, -1, -1};
    
    vector<int> get_dir(const string& piece) {
        if (piece == "rook") {
            return {0, 2, 4, 6};
        } else if (piece == "queen") {
            return {0, 1, 2, 3, 4, 5, 6, 7};
        } else {
            return {1, 3, 5, 7};
        }
    }
    
    bool ok(vector<int> from1, vector<int> to1, vector<int> from2, vector<int> to2) {
        int d1 = to1[2], d2 = to2[2];
        to1.pop_back(), to2.pop_back();
        while (!(from1==to1 && from2==to2)) {
            if (from1 != to1) {
                from1[0] += dx[d1];
                from1[1] += dy[d1];
            }
            if (from2 != to2) {
                from2[0] += dx[d2];
                from2[1] += dy[d2];
            }
            if (from1 == from2) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<vector<int>>>& dests, 
             vector<vector<int>>& from, vector<vector<int>>& tars, int i) {
        if (i==dests.size()) {
            ++ans;
        } else {
            for (auto& dest : dests[i]) {
                bool all_fit = true;
                for (int x=0; x<i; ++x)
                    if (!ok(from[x], tars[x], from[i], dest)) {
                        all_fit = false;
                        break;
                    }
                if (all_fit) {
                    tars.push_back(dest);
                    dfs(dests, from, tars, i+1);
                    tars.pop_back();
                }
            }
        }
    }
    
    int countCombinations(vector<string>& pc, vector<vector<int>>& pos) {
        vector<vector<vector<int>>> dests;
        for (int i=0; i<pc.size(); ++i) {
            --pos[i][0], --pos[i][1];
            vector<int> drs = get_dir(pc[i]);
            vector<vector<int>> dest;
            for (auto dr : drs) {
                int tx=pos[i][0]+dx[dr], ty=pos[i][1]+dy[dr];
                while (tx>=0 && tx<8 && ty>=0 && ty<8) {
                    dest.push_back({tx, ty, dr});
                    tx += dx[dr], ty += dy[dr];
                }
            }
            dest.push_back({pos[i][0], pos[i][1], 0});
            dests.push_back(dest);
        }
        vector<vector<int>> tars;
        dfs(dests, pos, tars, 0);
        return ans;
    }
};