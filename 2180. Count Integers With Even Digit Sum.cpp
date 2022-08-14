class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int x=1; x<=num; ++x) {
            int s = 0;
            for (auto t=x; t; t/=10) s += t%10;
            if (!(s & 1)) ++ans;
        }
        return ans;
    }
};