class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        sort(a.rbegin(), a.rend());
        long long s = 0;
        for (int i=0; i<k; ++i) {
            s += max(0, a[i]-i);
        }
        return s;
    }
};