class RangeModule {
public:
    
    // https://leetcode.com/problems/range-module/description/
    // set O(nlogn) time O(n) space
    
    set<pair<int,int>> st;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = st.lower_bound({left, INT_MIN});
        
        // merge with left interval
        if (it!=st.begin() && prev(it,1)->second>=left) {
            --it;
            left = it->first;
            right = max(right, it->second);
            it = st.erase(it);
        }
        // merge with right intervals
        while (it!=st.end() && it->first<=right) {
            right = max(right, it->second);
            it = st.erase(it);
        } 
        st.insert({left, right});
    }
    
    bool queryRange(int left, int right) {
        auto p = st.lower_bound({left+1, INT_MIN});
        return p!=st.begin() && prev(p,1)->second>=right;
    }
    
    void removeRange(int left, int right) {
        auto it = st.lower_bound({left, INT_MIN});
        // remove left
        if (it!=st.begin() && prev(it,1)->second>left) {
            --it;
            st.insert({it->first, left});
            if (it->second>right) st.insert({right, it->second});
            it = st.erase(it);
        }
        
        // remove right
        while (it!=st.end() && it->first<right) {
            if (it->second>right) 
                st.insert({right, it->second});
            it = st.erase(it);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */