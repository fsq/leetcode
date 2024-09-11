class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
        for (auto& e : edges) ++ind[e[1]];
        int ans = -1;
        for (int i=0; i<n; ++i)
            if (ind[i] == 0) {
                if (ans != -1) return -1;
                ans = i;
            }
        return ans;
    }
};