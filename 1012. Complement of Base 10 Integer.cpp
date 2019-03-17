class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1;
        int x = 1 << (int)ceil(log(n)/log(2));
        return x==n ? x-1 : x-n-1;
    }
};