class Solution {
public:
    
    // https://leetcode.com/problems/maximum-average-subarray-ii/description/
    // O(nlog(MAX-MIN)) binary search
    
    bool valid(const vector<int>& a, int k, double x) {
        
        // exist (s[i]-s[j])/(i-j)>=x
        // ->    s[i]-i*x >= s[j]-j*x
        // record the minumum s[j]-j*x
        
        double minsj = INT_MAX;
        for (int i=0; i<a.size(); ++i) {
            if (i-k>=0)
                minsj = min(minsj, a[i-k]-(i-k)*x);
            if (a[i]-i*x>=minsj)
                return true;
        }
        return false;
    }
    
    double findMaxAverage(vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        vector<int> s(nums.size(), 0);
        partial_sum(nums.begin(), nums.end(), s.begin());
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