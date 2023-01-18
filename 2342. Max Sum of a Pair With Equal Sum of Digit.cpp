class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> m(82, -1);
        int ans = -1;
        for (auto x : nums) {
            int s = 0, tx = x;
            while (tx) {
                s += tx % 10;
                tx /= 10;
            }
            if (m[s] != -1) {
                ans = max(ans, m[s] + x);
            }
            m[s] = max(m[s], x);
        }
        return ans;
    }
};