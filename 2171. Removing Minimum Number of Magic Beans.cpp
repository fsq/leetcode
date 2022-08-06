class Solution {
public:
    long long minimumRemoval(vector<int>& a) {
        sort(a.begin(), a.end());
        long long s = accumulate(a.begin(), a.end(), 0ll), ans = s;
        for (int i=0; i<a.size(); ++i) {
            ans = min<long long>(ans, s - (long long)a[i]*(a.size()-i));
        }
        return ans;
    }
};