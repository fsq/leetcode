class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mf=0, ans=0;
        unordered_map<int, int> f;
        for (auto x : nums) {
            ++f[x];
            if (f[x] == mf) {
                ans += f[x];
            } else if (f[x] > mf) {
                mf = ans = f[x];
            }
        }
        return ans;
    }
};