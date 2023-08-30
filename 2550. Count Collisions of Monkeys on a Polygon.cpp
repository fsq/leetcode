class Solution {
public:

    const int M = 1000000007;

    int pow2(int n) {
        if (n==0) return 1;
        if (n==1) return 2;
        long long s = pow2(n/2);
        if (n & 1) {
            return s * s *2 % M;
        } else {
            return s * s % M;
        }
    }

    int monkeyMove(int n) {
       int s = pow2(n);
       return (s - 2 + M) % M; 
    }
};