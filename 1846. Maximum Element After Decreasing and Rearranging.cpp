class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        sort(a.begin(), a.end());
        int prev = 1;
        for (int i=1; i<a.size(); ++i) {
            a[i] = min(prev + 1, a[i]);
            prev = a[i];
        }
        return prev;
    }
};