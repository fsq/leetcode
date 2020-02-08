class Solution {
public:
    int numberOfSteps (int n) {
        int ans = 0;
        while (n) {
            ++ans;
            if (n & 1) 
                n -= 1;
            else 
                n >>= 1;
        }
        return ans;
    }
};