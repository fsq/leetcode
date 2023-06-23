class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        sort(a.begin(), a.end());
        long long sum = accumulate(a.begin(), a.end(), 0ll), d = sum / (a.size()/2);
        long long ans = 0;
        for (int i=0, j=a.size()-1; i<j; ++i, --j) {
            if (a[i] + a[j] != d) return -1;
            ans += a[i] * a[j];
        }
        return ans;
    }
};