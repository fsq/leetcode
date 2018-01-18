class Solution {
public:
    
    // https://leetcode.com/problems/longest-palindromic-subsequence/description/
    // O(n^2) time O(n) space DP solution
    // f[i][j] = length of longest palindromic subseq in s[i~j]
    // f[i][j] = max(f[i][j-1], f[i+1][j]), if s[i]!=s[j]
    // f[i][j] = f[i+1][j-1] + 2          , if s[i]==s[j]
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> pre(n, 0), f = pre;
        for (int i=n-1; i>=0; --i) {
            f[i] = 1;
            for (int j=i+1; j<n; ++j) 
                if (s[i]==s[j]) 
                    f[j] = pre[j-1]+2;
                else
                    f[j] = max(f[j], max(f[j-1], pre[j]));
            pre.swap(f);
        }
        return pre.back();
    }
};