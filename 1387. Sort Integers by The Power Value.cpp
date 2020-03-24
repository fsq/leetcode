class Solution {
public:
    
    int f(int x) {
        if (x==1) return 0;
        if (x & 1) return f(3*x+1)+1; else return f(x>>1)+1;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> a;
        for (int x=lo; x<=hi; ++x)
            a.push_back({f(x), x});
        nth_element(a.begin(), a.begin()+k-1, a.end());
        return a[k-1].second;
    }
};