class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ind(n), ans;
        for (auto& eg : edges) {
            ++ind[eg[1]];
        }
        
        for (int i=0; i<n; ++i)
            if (!ind[i])
                ans.push_back(i);
        
        return ans;
    }
};