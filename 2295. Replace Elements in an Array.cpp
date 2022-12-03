class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> first, last, ind;
        for (int i=0; i<nums.size(); ++i)
            ind[nums[i]] = i;
        for (int i=0; i<operations.size(); ++i) {
            auto& o = operations[i];
            nums[ind[o[0]]] = o[1];
            ind[o[1]] = ind[o[0]];
            ind.erase(o[0]);
        }
        return nums;
    }
};