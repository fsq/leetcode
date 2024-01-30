class Solution {
public:
    int countPairs(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0; i+1<a.size(); ++i) {
            // a[i]+a[j]<target==>a[j]<target-a[i];
            auto it = lower_bound(a.begin(), a.end(), target-a[i]) - a.begin();
            if (it > 0 && it-1>i) {
                ans += it - i - 1;
            }
        }
        return ans;
    }
};