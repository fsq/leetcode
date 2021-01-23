class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, x = 0;
        for (auto y : gain)
            ans = max(ans, x += y);
        return ans;
    }
};