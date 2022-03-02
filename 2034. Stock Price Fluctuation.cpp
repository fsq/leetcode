class StockPrice {
public:
    int max_tm = -1, x = 0;
    unordered_map<int, int> m;
    multiset<int> st;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (m.count(timestamp)) {
            st.erase(st.find(m[timestamp]));
        }
        st.insert(price);
        m[timestamp] = price;
        if (timestamp > max_tm) {
            max_tm = timestamp;
            x = price;
        } else if (timestamp == max_tm) {
            x = price;
        }
    }
    
    int current() {
        return x;
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */