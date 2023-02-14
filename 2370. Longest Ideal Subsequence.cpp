class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> pre(26), now(26);
        for (auto x : s) {
            for (int p=max<int>('a', x-k); p<=min<int>('z', x+k); ++p)
                now[x-'a'] = max(now[x-'a'], pre[p-'a'] + 1);
            pre = now;
        }
        return *max_element(now.begin(), now.end());
    }
};