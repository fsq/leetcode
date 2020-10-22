class Fancy {
public:
    long long a, b;
    vector<vector<long long>> x;
    const int M = 1e9 + 7;
    
    Fancy() {
        a = 1, b = 0;    
    }
    
    long long pow(long long a, long long b) {
        if (b==0) return 1;
        if (b==1) return a;
        long long hf = pow(a, b>>1);
        if (b & 1)
            return hf * hf % M * a % M;
        else 
            return hf * hf % M;
    }
    
    long long div(long long a, long long b) {
        long long g = gcd(a, b);
        a /= g, b /= g;
        return a * pow(b, M-2) % M;
    }
    
    void append(int val) {
        x.push_back({val, a, b});
    }
    
    void addAll(int inc) {
        b = (b + inc) % M;
    }
    
    void multAll(int m) {
        a = (a * m) % M;
        b = (b * m) % M;
    }
    
    int getIndex(int idx) {
        if (idx >= x.size()) return -1;
        long long base = x[idx][0];
        long long c = x[idx][1], d = x[idx][2];
        long long p = div(a, c);
        long long q = ((b - d * p) % M + M) % M;
        return (base * p + q) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

// (cx+d)p+q = ax+b
// cpx + dp + q = ax + b
// p = a/c
// q = b - dp