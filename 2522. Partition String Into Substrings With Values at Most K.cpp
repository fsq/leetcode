class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0, r = 0;
        while (r<s.size()) {
            long long x = 0;
            while (r<s.size() && (x*10+s[r]-'0')<=k) {
                x = x * 10 + (s[r++]-'0');
            }
            if (x==0) return -1;
            ++ans;
        }
        return ans;
    }
};