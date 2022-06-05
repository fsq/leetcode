class SORTracker {
public:
    
    struct cmp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) const {
            return a.first>b.first || a.first==b.first && a.second<b.second;
        }
    };
    
    set<pair<int, string>, cmp> st;
    set<pair<int, string>, cmp>::iterator it;
    
    SORTracker() {
    }
    
    void add(string name, int score) {
        auto x = pair<int, string>{score, name};
        if (st.empty()) {
            st.insert(x);
            it = st.begin();
        } else {
            st.insert(x);
            const auto& func = cmp();
            if (it==st.end() || func(x, *it)) {
                --it;
            }
        }
    }
    
    string get() {
        auto ans = it->second;
        ++it;
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */