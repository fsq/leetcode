class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (k==0) return num%10==0 ? 1 : -1;
        for (int s=1; s*k<=num; ++s) {
            if ((num-s*k) % 10 == 0) return s;
        }
        return -1;
    }
};