class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26);
        for (auto c : s) ++cnt[c-'a'];
        string ans;
        for (int j=24, i=25; i>=0; --i)
            if (cnt[i]==0)
                continue;
            else {
                while (cnt[i] > repeatLimit) {
                    ans += string(repeatLimit, 'a'+i);
                    cnt[i] -= repeatLimit;
                    while (j>=0 && (j>=i || cnt[j]==0)) --j;
                    if (j<0) break;
                    ans += string(1, 'a'+j);
                    --cnt[j];
                }
                if (j<0) break;
                ans += string(cnt[i], 'a'+i);
            }
        return ans;
    }
};