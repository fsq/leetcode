class Solution {
public:
    long long flowerGame(int n, int m) {
        long long o1 = (n+1)/2, e1 = n-o1;
        long long o2 = (m+1)/2, e2 = m-o2;
        return o1*e2 + o2*e1;
    }
};