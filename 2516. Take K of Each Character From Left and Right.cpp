class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> c(3);
        int l, r;
        for (l=0; l<s.size() && !(c[0]>=k && c[1]>=k && c[2]>=k); ++l)
            ++c[s[l]-'a'];
        --l;
        if (c[0]<k || c[1]<k || c[2]<k) return -1;
        int ans = l+1;
        r = s.size();
        for (; l>=0; --l) {
            --c[s[l]-'a'];
            while (c[s[l]-'a'] < k) {
                --r;
                ++c[s[r]-'a'];
            }
            ans = min<int>(ans, l + s.size()-r);
        }
        return ans;
    }
};