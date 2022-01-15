class Solution {
public:
    
    int rep(string& s, string& t) {
        int i = 0, r = 0;
        for (auto c : s) {
            if (c == t[i]) {
                ++i;
                if (i==t.size()) {
                    i = 0;
                    ++r;
                }
            }
        }
        return r;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> cnt;
        for (auto c : s) ++cnt[c];
        string cand;
        for (char c='z'; c>='a'; --c)
            if (cnt[c]>=k)
                cand.push_back(c);

        queue<string> q;
        q.push("");
        string ans;
        while (q.size()) {
            auto t = q.front(); q.pop();
            for (auto nxt : cand) {
                string tn = t;
                tn.push_back(nxt);
                if (rep(s, tn) >= k) {
                    q.push(tn);
                    if (tn.size() > ans.size()) ans = tn;
                }
            }
        }
        return ans;
    }
};