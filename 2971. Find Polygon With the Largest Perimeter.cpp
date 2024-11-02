class Solution {
public:
    long long largestPerimeter(vector<int>& a) {
        sort(a.begin(), a.end());
        long long s = a[0] + a[1], ans = -1;
        for (int i=2; i<a.size(); ++i) {
            if (s > a[i]) {
                ans = s + a[i];
            }
            s += a[i];
        }
        return ans;
    }
};