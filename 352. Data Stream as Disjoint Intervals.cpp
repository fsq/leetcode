class SummaryRanges {
public:
    set<vector<int>> st;
    
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> p = {val, val};
        auto it = st.upper_bound({val+1, INT_MIN});
        if (it != st.end() && (*it)[0]==val+1) {
            p[1] = (*it)[1];
            it = st.erase(it);
        }
        if (it != st.begin()) {
            it = prev(it);
            if ((*it)[1] >= val) return;
            if ((*it)[1]+1 == val) {
                p[0] = (*it)[0];
                st.erase(it);
            }
        }
        st.insert(p);
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(st.begin(), st.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */