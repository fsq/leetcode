class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int non_dist = 0;
        unordered_map<int, int> m;
        for (auto x : nums) 
            if (++m[x] == 2)
                ++non_dist;
        if (non_dist == 0) return 0;
        for (int i=0; i<nums.size(); i+=3) {
            for (int j=i; j<i+3 && j<nums.size(); ++j) {
                if (--m[nums[j]] == 1) --non_dist;
            }
            if (non_dist == 0) {
                return i/3 + 1;
            }
        }
        return (nums.size()+2) / 3;
    }
};