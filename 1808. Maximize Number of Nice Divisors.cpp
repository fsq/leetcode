class Solution {
public:
    
    const int M = 1000000007;
    
    long long pow(int p) {
        if (p==0)
            return 1;
        else if (p==1)
            return 3;
        else {
            long long s = pow(p/3);
            s = (s * s) % M * s % M;
            if (p%3 == 1) 
                s = s * 3 % M;
            else if (p%3 == 2)
                s = s * 9 % M;
            return s;
        }
    }
    
    int maxNiceDivisors(int x) {
        if (x == 1) return 1;
        if (x % 3 == 0)
            return pow(x / 3);
        else if (x % 3 == 1) {
            return pow(x/3-1) * 4 % M;
        } else {
            return pow(x/3) * 2 % M;
        }
    }
};
