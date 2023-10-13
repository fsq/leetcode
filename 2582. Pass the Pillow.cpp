class Solution {
public:
    int passThePillow(int n, int time) {
        int a = (time/(n-1)) & 1, b = time % (n-1);
        return a ? (n-b) : (1+b);
    }
};