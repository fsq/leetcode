class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int s = accumulate(a.begin(), a.end(), 0);
        if (s < x) return -1;
        if (s == x) return a.size();
        int ans = INT_MAX;
        for (int r=0, l=-1; l<(int)a.size(); ++l) {
            s += l>=0 ? a[l] : 0;
            while (s>x && r<a.size()) {
                s -= a[r];
                ++r;
            }
            if (s==x) ans = min<int>(ans, l+1 + a.size()-r);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};