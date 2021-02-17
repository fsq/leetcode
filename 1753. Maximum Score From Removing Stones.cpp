class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        
        if (a==0 && b==0) return 0;
        return 1 + maximumScore(a, b-1, c-1);
    }
};