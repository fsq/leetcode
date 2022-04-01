class Solution {
public:
    int countValidWords(string sentence) {
        istringstream sin(sentence);
        string s;
        int ans = 0;
        while (sin >> s) {
            bool ok = true, has_hyphen = false;
            for (int i=0; i<s.size(); ++i)
                if (isdigit(s[i])) {
                    ok = false;
                    break;
                } else if (s[i]=='-') {
                    if (has_hyphen || 
                        i==0 || !islower(s[i-1]) ||
                        i+1==s.size() || !islower(s[i+1])) {
                        ok = false;
                        break;
                    }
                    has_hyphen = true;
                } else if (ispunct(s[i])) {
                    if (i+1 != s.size()) {
                        ok = false;
                        break;
                    }
                }
            if (ok) ++ans;
        }
        return ans;
    }
};