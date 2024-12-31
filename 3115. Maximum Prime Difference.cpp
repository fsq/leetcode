class Solution {
public:

    bool isP(int x) {
        if (x==1) return false;
        for (int i=2; i*i<=x; ++i)
            if (x % i == 0)
                return false;
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int mn=INT_MAX, mx=-1;
        for (int i=0; i<nums.size(); ++i)
            if (isP(nums[i])) {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        return mx - mn;
    }
};