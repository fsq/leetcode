class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string mn = s, mx = s;
        int i = 0;
        for (; i<s.size() && s[i]=='1' || s[i]=='0'; ++i);
        if (i < s.size()) {
            char rp = s[i];
            char to = i==0 ? '1' : '0';
            for (; i<s.size(); ++i)
                if (mn[i]==rp)
                    mn[i] = to;
        }
        for (i=0; i<s.size() && s[i]=='9'; ++i);
        if (i < s.size()) {
            char rp = s[i];
            for (; i<s.size(); ++i)
                if (mx[i]==rp)
                    mx[i] = '9';
        }
        return stoi(mx) - stoi(mn);
    }
};