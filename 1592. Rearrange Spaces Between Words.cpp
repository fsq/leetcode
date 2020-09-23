class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> a;
        int ns = 0;
        string cur;
        for (auto c : text)
            if (c==' ') {
                ++ns;
                if (cur.size()) {
                    a.push_back(cur);
                    cur.clear();
                }
            } else {
                cur.push_back(c);
            }
        if (cur.size()) a.push_back(cur);
        
        if (a.size() == 1) {
            return a[0] + string(ns, ' ');
        } 
        
        int d = ns / (a.size() - 1), r = ns - d * (a.size() - 1);
        string ans;
        for (int i=0; i<a.size(); ++i) {
            ans += a[i];
            if (i+1 < a.size()) ans += string(d, ' ');
        }
        ans += string(r, ' ');
        return ans;
    }
};