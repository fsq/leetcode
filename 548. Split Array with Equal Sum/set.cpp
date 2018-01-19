class Solution {
public:
    // https://leetcode.com/problems/split-array-with-equal-sum/description/
    // O(n^2) time O(n) space using set
    
    bool splitArray(vector<int>& nums) {
        if(nums.size() < 7) return false;
        
        // for specific test cases
        // while(nums.size() > 7 && nums[0] == 0)
        //     nums.erase(nums.begin());
        // while(nums.size() > 7 && nums.back() == 0)
        //     nums.pop_back();
        
        int n = nums.size();
        vector<int> s(n, 0);    
        partial_sum(nums.begin(), nums.end(), s.begin());
        
        unordered_set<int> st;
        
        // enumerate j 
        for (int j=3; j+3<n; ++j) {
            st.clear();
            
            // find all i in [1,j-2] such that s[i-1]==s[j-1]-s[i]
            for (int i=1; i+1<j; ++i)
                if (s[i-1]+s[i]==s[j-1])
                    st.insert(s[i-1]);
            
            // find all k in [j+2,n-2] such that s[n-1]-s[k]==s[k-1]-s[j]
            // and check existence of i before j such that s[n-1]-s[k]==s[i-1]
            for (int k=j+2; k<n-1; ++k)
                if (s[k-1]-s[j]==s[n-1]-s[k] && st.find(s[n-1]-s[k])!=st.end())
                    return true;
        }
        return false;
    }
};