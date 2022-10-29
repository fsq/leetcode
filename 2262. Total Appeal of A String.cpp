class Solution {
public:
    long long appealSum(string s) {
        vector<int> p(26);
        long long ans = 0;
        for (int i=0; i<s.size(); ++i) {
            p[s[i]-'a'] = i + 1;
            ans += accumulate(p.begin(), p.end(), 0ll);
        }
        return ans;
    }
};