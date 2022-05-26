class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto pr = minmax_element(nums.begin(), nums.end());
        int i = pr.first-nums.begin(), j = pr.second-nums.begin();
        if (i > j) swap(i, j);
        return min<int>(j+1, min<int>(nums.size()-i, i+1+nums.size()-j));
    }
};