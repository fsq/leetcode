class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& a) {
        int len = INT_MIN, ans = 0;
        for (auto& b : a) {
            int cur = min(b[0], b[1]);
            if (cur > len) {
                len = cur;
                ans = 1;
            } else if (cur == len)
                ++ans;
        }
        return ans;
    }
};