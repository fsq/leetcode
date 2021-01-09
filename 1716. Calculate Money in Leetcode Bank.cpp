class Solution {
public:
    int totalMoney(int n) {
        int s = 0, pm = 0, ans = 0;
        for (int i=0; i<n; ++i) {
            if (i % 7 == 0)
                s = ++pm;
            else 
                ++s;
            ans += s;
        }
        return ans;
    }
};