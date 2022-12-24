class Solution {
public:

    int f(vector<int>& s) {
        int ans = 0, p = 0;
        for (auto x : s) {
            p = max(p+x, x);
            ans = max(ans, p);
        }
        return ans;
    }

    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        int s1 = accumulate(a.begin(), a.end(), 0), s2 = accumulate(b.begin(), b.end(), 0);
        vector<int> d1(a.size()), d2(b.size());
        for (int i=0; i<a.size(); ++i) {
            d1[i] = a[i] - b[i];
            d2[i] = b[i] - a[i];
        }
        return max(s1+f(d2), s2+f(d1));
    }
};