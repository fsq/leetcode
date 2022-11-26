class BookMyShow {
public:
    
    vector<long long> rm, mx;
    int n, m;
    
    void update(int i) {
        rm[i] = rm[i*2] + rm[i*2+1];
        mx[i] = max(mx[i*2], mx[i*2+1]);
    }
    
    void build(int i, int l, int r) {
        if (l == r) {
            rm[i] = m;
            mx[i] = m;
        } else {
            int mid = (l+r) >> 1;
            build(i*2, l, mid);
            build(i*2+1, mid+1, r);
            update(i);
        }
    }
    
    BookMyShow(int _n, int _m) {
        n = _n;
        m = _m;
        rm.resize(4*n);
        mx.resize(4*n);
        build(1, 0, n-1);
    }
    
    vector<int> g(int i, int l, int r, int k, int maxRow) {
        vector<int> ret;
        if (l > maxRow || mx[i] < k || rm[i] < k) 
            ret = {INT_MAX, INT_MAX};
        else if (l == r) {
            ret = {l, m-(int)rm[i]};
            rm[i] -= k;
            mx[i] = rm[i];
        } else {
            int mid = (l+r) >> 1;
            ret = g(i*2, l, mid, k, maxRow);
            if (ret[0] == INT_MAX) {
                ret = g(i*2+1, mid+1, r, k, maxRow);
            }
            update(i);
        }
        return ret;
    }
    
    vector<int> gather(int k, int maxRow) {
        auto ret = g(1, 0, n-1, k, maxRow);
        return ret[0] == INT_MAX ? vector<int>() : ret;
    }
    
    void use(int i, int l, int r, int k, int maxRow) {
        if (l > maxRow || rm[i] < k) 
            return;
        else if (l == r) {
            rm[i] -= k;
            mx[i] = rm[i];
        } else {
            int mid = (l+r) >> 1;
            if (rm[i*2] >= k)
                use(i*2, l, mid, k, maxRow);
            else {
                int t = rm[i*2];
                use(i*2, l, mid, t, maxRow);
                use(i*2+1, mid+1, r, k-t, maxRow);
            }
            update(i);
        }
    }
    
    long long sum(int i, int l, int r, int maxRow) {
        if (l > maxRow)
            return 0;
        else if (l==r || r <= maxRow)
            return rm[i];
        else {
            int mid = (l+r) >> 1;
            return sum(i*2, l, mid, maxRow) + sum(i*2+1, mid+1, r, maxRow);
        }
    }
    
    bool scatter(int k, int maxRow) {
        long long sm = sum(1, 0, n-1, maxRow);
        if (sm >= k) {
            use(1, 0, n-1, k, maxRow);
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */