class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen, ans;
        int k = 0;
        for (auto x : nums) {
            if (x == -1) {
                ++k;
                if (k <= seen.size()) {
                    ans.push_back(seen[seen.size() - k]);
                } else {
                    ans.push_back(-1);
                }
            } else {
                k = 0;
                seen.push_back(x);
            }
        }
        return ans;
    }
};