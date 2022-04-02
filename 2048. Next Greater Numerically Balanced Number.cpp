class Solution {
public:
    
    bool ok(int x) {
        vector<int> c(10);
        while (x) {
            int y = x%10; 
            x /= 10;
            if (++c[y]>y) return false;
        }
        for (int i=1; i<c.size(); ++i)
            if (c[i]>0 && c[i] != i)
                return false;
        return true;
    }
    
    int nextBeautifulNumber(int n) {
        while (++n)
            if (ok(n))
                return n;
        return 666666;
    }
};