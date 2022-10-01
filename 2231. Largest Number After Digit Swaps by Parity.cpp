class Solution {
public:
    int largestInteger(int num) {
        auto s = to_string(num), t = s;
        string ans(s.size(), ' ');
        sort(s.rbegin(), s.rend());
        int i=0, j=0;
        for (auto c : s)
            if ((c-'0')&1) {
                while (!((t[i]-'0') & 1)) ++i;
                ans[i] = c;
                ++i;
            } else {
                while ((t[j]-'0') & 1) ++j;
                ans[j] = c;
                ++j;
            }
        return stoi(ans);
    }
};