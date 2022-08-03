class Bitset {
public:
    
    string s;
    int cnt = 0, fl = 0;
    
    Bitset(int size) {
        s = string(size, '0');
    }
    
    void fix(int idx) {
        if (!((s[idx] - '0') ^ fl)) {
            s[idx] = (fl ^ 1) + '0';
            ++cnt;
        }
    }
    
    void unfix(int idx) {
        if ((s[idx] - '0') ^ fl) {
            s[idx] = fl + '0';
            --cnt;
        }
    }
    
    void flip() {
        fl ^= 1;
        cnt = s.size() - cnt;
    }
    
    bool all() {
        return cnt==s.size();
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        auto t = s;
        if (fl)
            for (auto& c : t)
                c = '1' - (c - '0');
        return t;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */