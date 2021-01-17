class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& a) {
        int ans = INT_MAX;
        for (auto& b : a) ans = min(ans, min(b[0], b[1]));
        return ans;
    }
};