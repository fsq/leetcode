class Solution {
public:
    string largestMultipleOfThree(vector<int>& a) {
        vector<int> c(10);
        int s = 0;
        for (auto x : a) {
            ++c[x];
            s += x;
        }
        if (s%3 == 1) {
            for (int i=1; i<10; i+=3) 
                if (c[i]) {
                    --c[i];
                    s -= i;
                    goto last;
                }
            int need = 2;
            for (int i=2; i<10 && need; i+=3) 
                if (c[i]) {
                    int use = min(c[i], need);
                    c[i] -= use;
                    need -= use;
                    s -= i * use;
                }
        } else if (s%3 == 2) {
            for (int i=2; i<10; i+=3)
                if (c[i]) {
                    --c[i];
                    s -= i;
                    goto last;
                }
            int need = 2;
            for (int i=1; i<10 && need; i+=3) 
                if (c[i]) {
                    int use = min(c[i], need);
                    c[i] -= use;
                    need -= use;
                    s -= i * use;
                }
        }
        last:
        if (s % 3 != 0) return "";
        string ans;
        for (int i=9; i>=0; --i)
            ans += string(c[i], i+'0');
        if (ans.size() && ans[0]=='0') return "0";
        return ans;
    }
};