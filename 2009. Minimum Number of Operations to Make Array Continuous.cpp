class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int ans = n;
        for (int l=0, r=0; l<a.size(); ++l) {
            while (r<a.size() && a[r]<=a[l]+n-1) ++r;
            ans = min<int>(ans, n - (r-l));
        }
        return ans;
    }
};