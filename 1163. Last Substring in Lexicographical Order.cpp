class Solution {
public:
    string lastSubstring(string s) {
        char mx = 0;
        vector<int> p;
        for (int i=0; i<s.size(); ++i)
            if (s[i] > mx) {
                mx = s[i];
                p = {i};
            } else if (s[i] == mx)
                p.push_back(i);
        int ans = p.back();
        for (int i=(int)p.size()-2; i>=0; --i) {
            int x=p[i], y=ans;
            for (;x<ans && y<s.size() && s[x]==s[y]; ++x,++y);
            if (x==ans || y==s.size() || s[y] < s[x]) ans = p[i];
        }
        return s.substr(ans);
    }
};