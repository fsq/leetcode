class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s!="1") {
            if (s.back()=='1') {
                int i;
                for (i = s.size()-1; i>=0 && s[i]=='1'; --i)
                    s[i] = '0';
                if (i >= 0) s[i] = '1';
                    else    s = "1" + s;
            } else 
                s.pop_back();
            ++ans;
        }
        return ans;
    }
};