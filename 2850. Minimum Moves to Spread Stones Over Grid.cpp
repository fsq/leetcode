class Solution {
public:
    int minimumMoves(vector<vector<int>>& a) {
        int n = 3;
        vector<pair<int,int>> src, dst;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (a[i][j] == 0) {
                    dst.push_back({i, j});
                } else if (a[i][j]>1) {
                    for (int k=2; k<=a[i][j]; ++k)
                        src.push_back({i, j});
                }
        sort(src.begin(), src.end());
        int mind = INT_MAX;
        do {
            int d = 0;
            for (int i=0; i<src.size(); ++i)
                d += abs(src[i].first-dst[i].first) + abs(src[i].second-dst[i].second);
            mind = min(d, mind);
        } while (next_permutation(src.begin(), src.end()));
        return mind;
    }
};