class NumArray {
public:
    
    // https://leetcode.com/problems/range-sum-query-immutable/description/
    
    vector<int> s;
    NumArray(vector<int> nums) {
        s = vector<int>(nums.size(), 0);
        partial_sum(nums.begin(), nums.end(), s.begin());
    }
    
    int sumRange(int i, int j) {
        return s[j] - (i==0 ? 0 : s[i-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */