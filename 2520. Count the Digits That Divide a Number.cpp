class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        for (auto x = num; x; x/=10) {
            int b = x % 10;
            if (num % b == 0) ++ans;
        }
        return ans;
    }
};