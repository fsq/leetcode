class Solution {
public:
    
    // https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
    // unordered_map O(n) time O(n) space
    // or, sort O(nlogn) time O(1) space
    
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) 
            return 0;
        unordered_map<int, int> freq;
        for (auto x : nums) ++freq[x];
        
        int ans = 0;
        for (const auto& kv : freq) 
            if (k==0 && kv.second>1 || k>0 && freq.find(kv.first+k)!=freq.end())
                ++ans;
        return ans;
    }
};