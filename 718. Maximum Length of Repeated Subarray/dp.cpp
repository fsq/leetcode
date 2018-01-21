class Solution {
public:
    
    // https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
    // O(nm) DP
    // f[i][j] = max length of common subarray
    // f[i][j] = f[i-1][j-1]+1, if A[i]==B[j]
    // f[i][j] = max(f[i-1][j], f[i][j-1]), if A[i]!=B[j]
    
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int ans = 0;
        vector<int> pre(m+1, 0), f(m+1, 0);
        for (int i=0; i<A.size(); ++i) {
            fill(f.begin(), f.end(), 0);
            for (int j=0; j<B.size(); ++j) {
                f[j] = A[i]==B[j] ? 1 + (j>0 ? pre[j-1]:0 ) : 0;
                ans = max(ans, f[j]);
            }
            pre.swap(f);
        }
        return ans;
    }
};