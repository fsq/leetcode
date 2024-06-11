class Solution {
public:
    int minLengthAfterRemovals(vector<int>& a) {
        int x = a[a.size()/2];
        int cnt = upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x);
        if (cnt >= (a.size()+1)/2) {
            return a.size() - 2 * (a.size() - cnt);
        } else {
            return a.size() & 1;
        }
    }
};