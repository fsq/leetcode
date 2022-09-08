class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long a = 0, ans1 = 0, ans2 = 0;
        for (auto c : text) {
           if (c == pattern[1]) {
                ans1 += a + 1;
                ans2 += a;
            }
            if (c == pattern[0]) ++a;
        }
        ans2 += a;
        return max(ans1, ans2);
    }
};