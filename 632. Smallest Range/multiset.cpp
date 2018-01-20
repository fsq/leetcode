class Solution {
public:
    
    // https://leetcode.com/problems/smallest-range/description/
    // O(nlogk) time O(k) space
    // add the smallest element in each row to a priority_queue(multiset here)
    // range = [min, max]
    // pop the smallest element and add the next
    
    
    using VIT = vector<int>::iterator;
    
    struct cmp {
        bool operator() (const pair<VIT,VIT>& a, const pair<VIT,VIT>& b) {
            return *(a.first) < *(b.first);
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        // multiset use cmp to check if two elements are the same
        // i.e. !cmp(a,b) && !cmp(b,a)
        // cmp here only compares *iterators rather than iterators
        // so we must use multiset instead of set
        multiset<pair<VIT,VIT>, cmp> st;

        for (auto &row : nums)
            st.insert({row.begin(), row.end()});
        
        int l=-1e5, r=1e5;
        
        while (st.size()==k) {
            auto row = *st.begin();
            
            int max = *( prev(st.end(), 1)->first );
            if (max-*(row.first)<r-l) {
                l = *(row.first);
                r = max;
            }
            st.erase(st.begin());
            if (next(row.first, 1) != row.second) {
                ++row.first;
                st.insert(row);
            }
        }
        
        return {l, r};
    }
};