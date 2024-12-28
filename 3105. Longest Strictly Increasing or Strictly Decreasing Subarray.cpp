class Solution {
public:

    int f(vector<int>& a) {
        int ans = 1;
        for (int j,i=0; i<a.size(); i=j) {
            for (j=i+1; j<a.size() && a[j]>a[j-1]; ++j);
            ans = max(ans, j-i);
        }
        return ans;
    }

    int longestMonotonicSubarray(vector<int>& a) {
        auto b = a;
        reverse(b.begin(), b.end());
        return max(f(a), f(b));
    }
};