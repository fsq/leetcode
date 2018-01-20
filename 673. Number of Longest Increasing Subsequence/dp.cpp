class Solution {
public:
    
    // https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
    // O(nlogn) time O(n) space DP solution 
    
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // a[i] : vector of pair<last element, prefix sum> of length i
        // key observation: last element is non-increasing, otherwise we get a longer sequence
        vector<vector<pair<int,int>>> a; 
        vector<int> h; // to calculate length of LIS
        for (auto x : nums) {
            auto i = lower_bound(h.begin(), h.end(), x) - h.begin();
            
            int count = 0;
            if (i==0)
                count = 1;
            else {
                // find the first one < x
                auto p = upper_bound(a[i-1].begin(), a[i-1].end(), make_pair(x, INT_MIN), greater<pair<int,int>>());
                if (p==a[i-1].begin())
                    count = a[i-1].back().second;
                else
                    count = a[i-1].back().second - prev(p, 1)->second;
            }
            
            if (i==h.size()) {
                h.push_back(x);
                a.push_back({{x, count}});
            } else {
                h[i] = min(h[i], x);
                a[i].push_back({x, a[i].back().second+count});
            }
        }
        return a.back().back().second;
    }
};