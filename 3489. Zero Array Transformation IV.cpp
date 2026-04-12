class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> done(nums.size());
        int remain = nums.size();
        vector<bitset<1001>> vis(nums.size());
        for (int i=0; i<nums.size(); ++i)
            if (nums[i]==0) {
                done[i] = 1;
                --remain;
            } else {
                vis[i].set(0);
            }
        if (remain == 0) return 0;
        
        for (int k=0; k<queries.size(); ++k) {
            const auto l=queries[k][0], r=queries[k][1], val=queries[k][2];
            for (int i=l; i<=r; ++i) {
                if (done[i]) continue;
                vis[i] = vis[i] | (vis[i] << val);
                if (vis[i].test(nums[i])) {
                    done[i] = 1;
                    --remain;
                }
            }

            if (remain == 0) {
                return k+1;
            }
        }
        return -1;
    }
};
