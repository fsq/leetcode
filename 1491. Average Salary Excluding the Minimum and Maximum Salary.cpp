class Solution {
public:
    double average(vector<int>& salary) {
        int mn = INT_MAX, mx = INT_MIN, s = 0;
        for (auto x : salary) {
            mn = min(x, mn);
            mx = max(x, mx);
            s += x;
        }
        return (double)(s-mn-mx) / (salary.size() - 2);
    }
};