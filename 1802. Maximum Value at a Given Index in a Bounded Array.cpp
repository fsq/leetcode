class Solution {
public:
    
    long long sum(long long i, long long n, long long x) {
        long long s = x;
        auto r = n - i - 1, l = i;
        if (r <= x - 1) {
            s += (x-1 + (x-r)) * r / 2;
        } else {
            s += x * (x-1) / 2 + (r-x+1);
        }
        
        if (l <= x - 1) {
            s += (x-1 + (x-l)) * l / 2;
        } else {
            s += x * (x-1) / 2 + (l-x+1);
        }
        return s;
    }
    
    int maxValue(int n, int index, int maxSum) {
        long long l = 0, r = maxSum;
        while (l < r) {
            auto x = (l+r+1) >> 1;
            auto s = sum(index, n, x);
            if (s > maxSum) 
                r = x - 1;
            else 
                l = x;
        }
        return l;
    }
};