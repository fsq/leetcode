class Solution {
public:
    long long numberOfWeeks(vector<int>& a) {
        long long mx = *max_element(a.begin(), a.end());
        long long s = accumulate(a.begin(), a.end(), 0ll);
        return mx > s-mx ? 2*(s-mx)+1 : s;
    }
};
