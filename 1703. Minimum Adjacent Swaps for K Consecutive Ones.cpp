class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> a;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] == 1)
                a.push_back(i - a.size());

        int s = 0, med = k/2;
        for (int i=0; i<k; ++i)
            s += abs(a[i] - a[med]);
        int ans = s;

        for (int i=1; i+k-1<a.size(); ++i) {
            int new_med = i + k / 2;
            if (k % 2 == 0) {
                // exclude first element.
                s += a[new_med] - a[med];
            }
            s -= a[med] - a[i-1];
            s += a[i+k-1] - a[new_med];
            med = new_med;
            ans = min(ans, s);
        }
        return ans;
    }
};