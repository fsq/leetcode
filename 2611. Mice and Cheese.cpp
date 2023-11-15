class Solution {
public:
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        int ans = accumulate(b.begin(), b.end(), 0);
        for (int i=0; i<a.size(); ++i)
            a[i] -= b[i];
        sort(a.rbegin(), a.rend());
        for (int i=0; i<k; ++i) ans += a[i];
        return ans;
    }
};