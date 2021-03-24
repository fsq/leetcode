class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> d(n+1);
        unordered_map<int, unordered_map<int, int>> e;
        for (auto& g : edges) {
            ++e[g[0]][g[1]];
            ++e[g[1]][g[0]];
            ++d[g[0]];
            ++d[g[1]];
        }
        vector<int> a = d;
        sort(a.begin(), a.end());
        vector<int> ans;
        for (auto k : queries) {
            int tot = 0;
            for (int i=1, j=a.size()-1; i<j; )
                if (a[i] + a[j] > k) 
                    tot += (j--) - i;
                else 
                    ++i;
            for (int x=1; x<=n; ++x)
                for (auto& pr : e[x]) {
                    int y = pr.first, o = pr.second;
                    if (y>x && d[x]+d[y]>k && d[x]+d[y]<=k+o)
                        --tot;
                }
            ans.push_back(tot);
        }
        return ans;
    }
};