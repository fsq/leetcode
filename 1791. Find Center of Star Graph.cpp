class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> d;
        for (auto& pr : edges) {
            if (++d[pr[0]] > 1) return pr[0];
            if (++d[pr[1]] > 1) return pr[1];
        }
        return 0;
    }
};