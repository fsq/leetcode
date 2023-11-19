class Solution {
public:

    long long f(vector<int>& a, int d) {
        long long ans = 0;
        for (int i=0; i+1<a.size();)
            if (a[i+1]-a[i]<=d) {
                ++ans;
                i += 2;
            } else {
                ++i;
            }
        return ans;
    }

    int minimizeMax(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        int l = 0, r = a.back()-a.front();
        while (l < r) {
            int mid = (l+r) >> 1;
            long long pk = f(a, mid);
            if (pk < p) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};