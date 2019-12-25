class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> cnt;
        for (int i=0; i+minSize-1<s.size(); ++i) {
            vector<int> c(26);
            int uc = 0;
            string now;
            for (int j=i; j<i+minSize; ++j) {
                if (++c[s[j]-'a']==1) ++uc;
                if (uc > maxLetters) break;
                now += s[j];
            }
            if (uc <= maxLetters) ++cnt[now];
        }
        int ans = 0;
        for (auto& pr : cnt) ans = max(ans, pr.second);
        return ans;
    }
};