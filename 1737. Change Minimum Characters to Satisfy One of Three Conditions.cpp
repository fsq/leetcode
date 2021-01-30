class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> fa(26), fb(26);
        for (auto c : a) ++fa[c-'a'];
        for (auto c : b) ++fb[c-'a'];
        int sa=0, sb=0;
        int ans = b.size() + a.size()-*max_element(fa.begin(),fa.end())-*max_element(fb.begin(), fb.end());
        for (int i=0; i<25; ++i) {
            sa += fa[i], sb += fb[i];
            ans = min(ans, min<int>(a.size()-sa+sb, b.size()-sb+sa));
        }
        return ans;
    }
};