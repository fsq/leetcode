class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> a(n, 1);
        a.back() += k-n;
        for (int i=n-1; i>0; --i)
            if (a[i] > 26) {
                a[i-1] += a[i] - 26;
                a[i] = 26;
            }
        string ans;
        for (auto x : a)
            ans += 'a' + x-1;
        return ans;
    }
};