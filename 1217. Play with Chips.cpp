class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        vector<int> c(2);
        for (auto x : chips) ++c[x & 1];
        return min(c[0], c[1]);
    }
};