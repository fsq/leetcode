class Solution {
public:
    int minimumCost(vector<int>& a) {
        sort(a.rbegin(), a.rend());
        int ans = 0, i = 0;
        while (i+2 < a.size()) {
            ans += a[i] + a[i+1];
            i += 3;
        }
        while (i < a.size()) ans += a[i++];
        return ans;
    }
};