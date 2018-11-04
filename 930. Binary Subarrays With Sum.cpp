class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int s) {
        int n = a.size();
        vector<int> cnt(n+1);
        cnt[0] = 1;
        int sum = 0, ans = 0;
        for (auto x : a) {
            sum += x;
            if (sum>=s)
                ans += cnt[sum-s];
            ++cnt[sum];
        }
        return ans;
    }
};