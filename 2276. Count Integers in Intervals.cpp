class CountIntervals {
public:
    
    set<pair<int,int>> st;
    int cnt = 0;
    
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = st.lower_bound({left, -1});
        if (it != st.begin()) {
            auto x = prev(it);
            if (x->second >= left) {
                if (x->second<right) {
                    cnt -= x->second - x->first + 1;
                    left = x->first;
                    st.erase(x);
                } else {
                    return;
                }
            }
        }
        while (it != st.end() && it->first <= right) {
            cnt -= (it->second - it->first + 1);
            right = max(right, it->second);
            it = st.erase(it);
        }
        cnt += right - left + 1;
        st.insert({left, right});
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */