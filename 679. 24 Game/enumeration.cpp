class Solution {
public:
    
    // https://leetcode.com/problems/24-game/description/
    // enumeration
    
    const double EPS = 1e-6;
    
    vector<double> get_all(double x, double y) {
        vector<double> ret = {x+y,x-y,y-x,x*y};
        if (fabs(y)>EPS) ret.push_back(x/y);
        if (fabs(x)>EPS) ret.push_back(y/x);
        return ret;
    }
    bool judgePoint24(vector<int>& nums) {
        return judgePoint24(vector<double>(nums.begin(), nums.end()));
    }
    bool judgePoint24(vector<double> nums) {
        if (nums.size()==4) {
            for (auto x : get_all(nums[2], nums[3]))
                if (judgePoint24({nums[0], nums[1], x}))
                    return true;
            for (auto x : get_all(nums[1], nums[3]))
                if (judgePoint24({nums[0], nums[2], x}))
                    return true;
            for (auto x : get_all(nums[0], nums[3])) 
                if (judgePoint24({nums[1], nums[2], x}))
                    return true;
            for (auto x : get_all(nums[1], nums[2]))
                if (judgePoint24({nums[0], nums[3], x}))
                    return true;
            for (auto x : get_all(nums[0], nums[2]))
                if (judgePoint24({nums[1], nums[3], x}))
                    return true;
            for (auto x : get_all(nums[0], nums[1]))
                if (judgePoint24({nums[2], nums[3], x}))
                    return true;
        } else if (nums.size()==3) {
            for (auto x : get_all(nums[0], nums[1]))
                if (judgePoint24({nums[2], x}))
                    return true;
            for (auto x : get_all(nums[0], nums[2]))
                if (judgePoint24({nums[1], x}))
                    return true;
            for (auto x : get_all(nums[1], nums[2]))
                if (judgePoint24({nums[0], x}))
                    return true;
        } else if (nums.size()==2) {
            for (auto x : get_all(nums[0], nums[1]))
                if (fabs(x-24)<EPS)
                    return true;
        }
        return false;
    }
};