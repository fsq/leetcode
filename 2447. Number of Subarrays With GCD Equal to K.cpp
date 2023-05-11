class Solution {
public:
    int subarrayGCD(vector<int>& a, int k) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int d = a[i];
            for (int j=i; j<a.size() && a[j]>=k && d>=k; ++j) {
                d = gcd(d, a[j]);
                if (d==k) ++ans;
            }
        }
        return ans;
    }
};