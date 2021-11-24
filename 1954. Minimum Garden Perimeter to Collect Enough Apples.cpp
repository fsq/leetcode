class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1, r = 100000;
        while (l < r) {
            long long m = (l+r) >> 1;
            long long s = 2*m*(m+1)*(2*m+1);
            if (s < neededApples) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l * 8;
    }
};
// 1: 1+2+1
// 2: 2+3+4+3+2
// 3: 3+4+5+6+5+4+3
    
    
// x: 2*(x+...2x) - 2x
// = (3x*(x+1)) - 2x
// = 3x^2 + x

// f*4 - 4x
// = 12x^2

// 12 + 12*2^2 + 12*3^2 ...
// 12 * (n(n+1)(2n+1)) / 6 = 2n(n+1)(2n+1) >= x
