class SmallestInfiniteSet {
public:
    set<int> st;
    int x = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int ans;
        if (!st.empty()) {
            ans = *st.begin();
            st.erase(st.begin());
        } else {
            ans = x++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if (num < x) st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */