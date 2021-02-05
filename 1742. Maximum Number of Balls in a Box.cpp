class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i=lowLimit; i<=highLimit; ++i) {
            int s = 0;
            for (auto x=i; x; x/=10)
                s += x % 10;
            ans = max(ans, ++cnt[s]);
        }
        return ans;
    }
};