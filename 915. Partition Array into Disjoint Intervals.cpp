class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int ans=0, mx=a[0], prev=a[0];
        for (int i=1; i<a.size(); ++i) {
            if (prev>a[i]) {
                ans = i;
                prev = mx;
            }
            mx = max(mx, a[i]);
        }
        return ans+1;
    }
};