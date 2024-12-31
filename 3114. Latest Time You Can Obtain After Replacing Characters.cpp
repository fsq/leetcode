class Solution {
public:
    string findLatestTime(string t) {
        for (int h=11; h>=0; --h)
            for (int m=59; m>=0; --m) {
                string sh = to_string(h), sm = to_string(m);
                if (sh.size()==1) sh = "0" + sh;
                if (sm.size()==1) sm = "0" + sm;
                string s = sh + ":" + sm;
                bool ok = true;
                for (int i=0; i<s.size(); ++i)
                    if (!(s[i]==t[i] || t[i]=='?')) {
                        ok = false;
                        break;
                    }
                if (ok) return s;
            }
        return "";
    }
};