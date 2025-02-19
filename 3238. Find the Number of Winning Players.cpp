class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int, int>> m;
        unordered_set<int> st;
        for (auto& p : pick) {
            if (++m[p[0]][p[1]] == p[0]+1)
                st.insert(p[0]);
        }
        return st.size();
    }
};