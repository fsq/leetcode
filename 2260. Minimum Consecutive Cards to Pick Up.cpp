class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        unordered_map<int, int> pre;
        int ans = INT_MAX;
        for (int i=0; i<a.size(); ++i) {
            if (pre.count(a[i]))
                ans = min(ans, i - pre[a[i]] + 1);
            pre[a[i]] = i;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};