class Solution {
public:
    int maximumCount(vector<int>& nums) {
         int p=0, n=0;
         for (auto x : nums)
            if (x < 0)
                ++n;
            else if (x > 0)
                ++p;
        return max(p, n);
    }
};