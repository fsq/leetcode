class Solution {
public:
    // https://leetcode.com/problems/maximum-average-subarray-ii/description/
    // O(nlog(MAX-MIN)) binary search solution
    // check existence of i,j s.t. (s[i]-s[j])/(i-j) >= mid, where i-j>=k
    // ==> mid*j-s[j] >= mid*i-s[i]
    
    bool valid(const vector<int>& a, int k, double x) {
        double pre = INT_MIN;
        for (int i=0; i<a.size(); ++i) {
            if (i-k>=0)
                pre = max(pre, x*(i-k)-a[i-k]);
            if (pre >= x*i-a[i]) 
                return true;
        }
        return false;
    }
    
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> s(nums.size()+1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin()+1);
        auto min_max = minmax_element(nums.begin(), nums.end());
        
        double l=*min_max.first, r=*min_max.second;
        
        while (r-l>1e-5) {
            double mid = l + ((r-l)/2);
            if (valid(s, k, mid)) 
                l = mid;
            else 
                r = mid;
        }
        
        return (l+r)/2;
    }
};