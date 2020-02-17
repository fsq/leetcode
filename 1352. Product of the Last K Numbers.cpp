class ProductOfNumbers {
public:
    vector<long long> s;
    int last = -1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            s.push_back(1);
            last = s.size() - 1;
        } else {
            s.push_back(!s.size() ? num : s.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (s.size() <= last+k) return 0;
        return s.size()<=k ? s.back() : (s.back() / s[s.size()-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */