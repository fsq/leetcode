class Solution {
public:
    int findMinimumTime(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        do {
            int x = 1, t = 0;
            for (int y: a) {
                t += (y + x-1) / x;
                x += k;
            }
            ans = min(ans, t);
        } while (next_permutation(a.begin(), a.end()));
        return ans;
    }
};
