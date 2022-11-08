class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (char a='a'; a<='z'; ++a)
            for (char b='a'; b<='z'; ++b)
                if (a!=b) {
                    int df = 0, mn = 10001, buff = 0;
                    for (auto c : s) {
                        if (c==a)
                            ++df;
                        else if (c==b) {
                            mn = min(mn, buff);
                            buff = --df;
                        }
                        ans = max(ans, df - mn);
                    }
                }
        return ans;
    }
}; 