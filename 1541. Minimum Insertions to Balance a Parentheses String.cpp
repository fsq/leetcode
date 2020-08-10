class Solution {
public:
    int minInsertions(string s) {
        int sum = 0, ans = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i]=='(')
                sum += 2;
            else {
                if (i+1==s.size() || s[i+1] != ')')
                    ++ans;
                else 
                    ++i;
                sum -= 2;
            }
            if (sum < 0)
                ++ans, sum = 0;
        }
        while (sum > 0) {
            ans += 2;
            sum -= 2;
        }
        if (sum < 0)
            ans += 1;
        return ans;
    }
};