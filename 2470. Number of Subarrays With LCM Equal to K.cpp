class Solution {
public:
    int subarrayLCM(vector<int>& a, int k) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int b = a[i];
            for (int j=i; j<a.size(); ++j) {
                int d = gcd(b, a[j]);
                b = b/d * a[j];
                if (b==k) ++ans; else if (b>k) break;
            }
        }
        return ans;
    }
};