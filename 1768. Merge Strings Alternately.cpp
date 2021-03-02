class Solution {
public:
    string mergeAlternately(string a, string b) {
        string ans;
        int i = 0;
        while (i<a.size() && i<b.size()) {
            ans.push_back(a[i]);
            ans.push_back(b[i]);
            ++i;
        }
        ans += a.substr(i);
        ans += b.substr(i);
        return ans;
    }
};