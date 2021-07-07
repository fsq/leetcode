class Solution {
public:
    int minSwaps(string s) {
        int c0=0, c1=0;
        for (auto c : s)
            if (c == '0')
                ++c0;
            else 
                ++c1;
        if (abs(c0 - c1) > 1) return -1;
        int ans = INT_MAX;
        if (c0 >= c1) {
            int tot = 0;
            for (int i=0; i<s.size(); ++i)
                if (s[i] != '0'+(i&1)) 
                    ++tot;
            ans = min(ans, tot/2);
        }
        if (c1 >= c0) {
            int tot = 0;
            for (int i=0; i<s.size(); ++i)
                if (s[i] != '0'+(i&1^1)) 
                    ++tot;
            ans = min(ans, tot/2);
        }
        return ans;
    }
};