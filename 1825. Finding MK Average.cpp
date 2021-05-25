class MKAverage {
public:
    int m, k, s;
    queue<int> q;
    multiset<int> a, b, c, st;
    bool ok = false;
    
    MKAverage(int m_, int k_) {
        m = m_;
        k = k_;
        s = 0;
    }
    
    void init() {
        auto x = st.begin(), y = st.end(); 
        for (int i=0; i<k; ++i) {
            a.insert(*x);
            x = next(x);
            y = prev(y);
            c.insert(*y);
        }
        for (auto it=x; it!=y; ++it) {
            b.insert(*it);
            s += *it;
        }
    }
    
    void add(int num) {
        if (num >= *prev(a.end()) && num <= *c.begin()) {
            b.insert(num);
            s += num;
        } else if (num < *b.begin()) {
            a.insert(num);
        } else {
            c.insert(num);
        }
        if (a.size() > k) {
            s += *prev(a.end());
            b.insert(*prev(a.end()));
            a.erase(prev(a.end()));
        }
        if (c.size() > k) {
            s += *c.begin();
            b.insert(*c.begin());
            c.erase(c.begin());
        }
    }
    
    void pop(int num) {
        if (b.count(num)) {
            b.erase(b.lower_bound(num));
            s -= num;
        } else {
            if (num < *b.begin()) {
                a.erase(a.lower_bound(num));
            } else {
                c.erase(c.lower_bound(num));
            } 
            if (a.size() < k) {
                a.insert(*b.begin());
                s -= *b.begin();
                b.erase(b.begin());
            }
            if (c.size() < k) {
                c.insert(*prev(b.end()));
                s -= *prev(b.end());
                b.erase(prev(b.end()));
            }
        }
    }
    
    void addElement(int num) {
        q.push(num);
        if (q.size() <= m) st.insert(num);
        if (!ok && q.size() == m) {
            ok = true;
            init();
        } else if (ok) {
            add(num);
            pop(q.front());
            q.pop();
        }
    }
    
    int calculateMKAverage() {
        if (q.size() != m) return -1;
        return s / (m-k-k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */