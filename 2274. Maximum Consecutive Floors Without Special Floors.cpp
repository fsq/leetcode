class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int pre = bottom - 1, ans = 0;
        for (auto x : special)
            if (x > pre) {
                ans = max(ans, x - pre - 1);
                pre = x;
            }
        if (special.back() < top)
            ans = max(ans, top - special.back());
        return ans;
    }
};