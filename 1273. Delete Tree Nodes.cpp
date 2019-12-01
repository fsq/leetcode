class Solution {
public:
    
    pair<int,int> dfs(vector<vector<int>>& e, vector<int>& v, int x) {
        int sum=v[x], tot = 1;
        for (auto y : e[x]) {
            auto pr = dfs(e, v, y);
            sum += pr.first;
            tot += pr.second;
        }
        if (sum == 0)
            return {0, 0};
        else 
            return {sum, tot};
    }
    
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> e(n);
        for (int i=0; i<n; ++i)
            if (parent[i] != -1)
                e[parent[i]].push_back(i);
        auto pr = dfs(e, value, 0);
        return pr.second;
    }
};