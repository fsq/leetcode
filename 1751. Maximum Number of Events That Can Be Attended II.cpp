class Solution {
public:
    int maxValue(vector<vector<int>>& es, int k) {
        int mxe = 0;
        unordered_map<int, vector<vector<int>>> m;
        map<int, vector<int>> fs;
        
        for (auto& e : es) {
            fs[e[1]] = fs[e[0]-1] = vector<int>(k+1, -1);
            m[e[1]].push_back(e);
            mxe = max(mxe, e[1]);
        }
        fs[0] = vector<int>(k+1, -1);
        
        int ans = 0;
        fs[0][0] = 0;
        for (auto it=next(fs.begin()); it!=fs.end(); ++it) {
            int x = it->first;
            auto& f = it->second;
            f[0] = 0;
            for (int j=1; j<=k; ++j) {
                f[j] = (prev(it)->second)[j];
                if (m.count(x)) {
                    for (auto& e : m[x])
                        if (fs[e[0]-1][j-1]!=-1) {
                            f[j] = max(f[j], fs[e[0]-1][j-1] + e[2]);
                        }
                    ans = max(ans, f[j]);
                }
            }
        }
        return ans;
    }
};