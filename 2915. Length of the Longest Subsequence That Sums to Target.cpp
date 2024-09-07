class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& a, int target) {
        int n = a.size();
        vector<int> f(target+1, -1);
        f[0] = 0;
        for (int i=1; i<=n; ++i)
            for (int j=target; j>=a[i-1]; --j) {
                if (f[j-a[i-1]]!=-1)
                    f[j] = max(f[j], f[j-a[i-1]] + 1);
            }
        return f[target];
    }
};