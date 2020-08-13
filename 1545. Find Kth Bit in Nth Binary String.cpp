class Solution {
public:
    
    char f(int n, int k) {
        if (n==1) return '0';
        int mid = ((1 << n) - 1) >> 1;
        if (k==mid) 
            return '1';
        else if (k < mid) {
            return f(n-1, k);
        } else {
            auto c = f(n-1, (1<<(n-1))-1-k+mid);
            return c=='0' ? '1' : '0';
        }
    }
    
    char findKthBit(int n, int k) {
        return f(n, k-1);
    }
};