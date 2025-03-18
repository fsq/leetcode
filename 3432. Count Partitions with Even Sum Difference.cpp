class Solution {
public:
    int countPartitions(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        int ans = 0;
        for (int s=0, i=0; i+1<a.size(); ++i) {
            s += a[i];
            if (!(abs(sum-s-s) & 1)) {
                ++ans;
            }
        }
        return ans;
    }
};