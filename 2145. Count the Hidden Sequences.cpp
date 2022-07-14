class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx=0, mn=0, x=0;
        for (auto d : differences) {
            x += d;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        return max<int>(0, upper-lower - (mx-mn) + 1);
    }
};