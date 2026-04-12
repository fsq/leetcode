class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> done(nums.size());
        int remain = nums.size();
        vector<bitset<1001>> vis(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == 0) {
                done[i] = 1;
                --remain;
            } else {
                vis[i].set(0);
            }
        if (remain == 0)
            return 0;

        for (auto [k, query] : views::enumerate(queries)) {
            const auto l = query[0], r = query[1], val = query[2];
            for (auto i : views::iota(l, r + 1)) {
                if (done[i])
                    continue;
                vis[i] = vis[i] | (vis[i] << val);
                if (vis[i].test(nums[i])) {
                    done[i] = 1;
                    --remain;
                }
            }

            if (remain == 0) {
                return k + 1;
            }
        }
        return -1;
    }
};
