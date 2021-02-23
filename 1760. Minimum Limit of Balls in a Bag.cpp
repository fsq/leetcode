class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = (l + r) >> 1;
            int cnt = 0;
            for (auto x : nums) {
                cnt += x / m;
                if (x % m==0) --cnt;
            }
            if (cnt > maxOperations)
                l = m + 1;
            else 
                r = m;
        }
        return l;
    }
};