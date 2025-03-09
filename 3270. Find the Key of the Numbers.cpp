class Solution {
public:
    int generateKey(int a, int b, int c) {
        int key = 0;
        for (int m=1; m<=1000; m*=10) {
            key += m * min(min(a/m%10, b/m%10), c/m%10);
        }
        return key;
    }
};