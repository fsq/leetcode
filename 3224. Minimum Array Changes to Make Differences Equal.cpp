class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> m(k+1), gap(k+1);
        for (int i=0, j=nums.size()-1; i<j; ++i, --j) {
            // Max gap that can be achieved with one op
            gap[max(max(k-nums[i], nums[i]), max(k-nums[j], nums[j]))]++;
            m[abs(nums[i] - nums[j])]++;
        }
        int ans = nums.size() / 2;
        int i = 0, acc = 0;
        // cost of using X: 1*(#gap[i]>=X) + 2*(#gap[i]<X) - (#existing gap[i]==X)
        for (int x=0; x<=k; ++x) {
            // #gap[i]<X = #gap[i]<(X-1) + #gap[i]==X-1
            acc += x>0 ? gap[x-1] : 0;
            int cur = acc*2 + (nums.size()/2-acc) - m[x];
            ans = min(ans, cur);
        }
        return ans;
    }
};