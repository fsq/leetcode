class Solution {
public:
    int minimumAddedCoins(vector<int>& a, int target) {
        int s = 0, ans = 0;
        sort(a.begin(), a.end());
        for (int i=0; i<a.size() && s<target; )
            if (a[i] <= s+1) {
                s += a[i];
                ++i;
            } else {
                ++ans;
                s = 2*s + 1;
            }
        while (s < target) {
            s = 2*s + 1;
            ++ans;
        }
        return ans;
    }
};