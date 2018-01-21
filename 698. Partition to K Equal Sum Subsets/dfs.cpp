class Solution {
public:
    
    // https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
    // dfs with pruning 
    
    bool dfs(const vector<int>& a, vector<int>& buckets, int i, int avg) {
        if (i==a.size()) return true;
        
        // don't put a[i] into two buckets with same size
        unordered_set<int> vis;
        for (auto & bucket : buckets) 
            if (bucket+a[i]<=avg && vis.find(bucket)==vis.end()) {
                vis.insert(bucket);
                bucket += a[i];
                if (dfs(a, buckets, i+1, avg)) return true;
                bucket -= a[i];
            }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> buckets(k, 0);
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%k!=0) return false;
        int avg = sum / k;
        for (auto x : nums) if (x>avg) return false;
        
        return dfs(nums, buckets, 0, avg);
             
    }
};