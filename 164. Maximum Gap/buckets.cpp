class Solution {
public:
    
    // https://leetcode.com/problems/maximum-gap/description/
    // pigeon hold principle && bucket sort O(N) time O(N) space
    
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return 0;
        
        auto minmax_pr = minmax_element(nums.begin(), nums.end());
        int GAP = *minmax_pr.second - *minmax_pr.first;
        
        // when mingap==0, division by 0 err
        int mingap = max(1, GAP / (n-1));
        int buckets_size = GAP/mingap+1;
        
        vector<pair<int,int>> buckets(buckets_size, {-1, -1});
        for (auto x : nums) {
            int ind = (x-*minmax_pr.first) / mingap;
            if (buckets[ind].first==-1) 
                buckets[ind] = {x, x};
            else {
                buckets[ind].first = min(buckets[ind].first, x);
                buckets[ind].second = max(buckets[ind].second, x);
            }
        }
        
        int ans = 0, maxnow = buckets[0].second;
        for (int i=0; i<buckets.size(); ++i) 
            if (buckets[i].first!=-1) {
                ans = max(ans, buckets[i].first-maxnow);
                maxnow = buckets[i].second;
            }
        
        return ans;
    }
};