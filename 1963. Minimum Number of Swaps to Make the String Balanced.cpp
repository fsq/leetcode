class Solution {
public:
    int minSwaps(string s) {
        int t = 0, ans = 0, i = 0, j = s.size()-1;
        while (i < j) {
            if (t + (s[i]=='[' ? 1 : -1) < 0) {
                while (i<j && s[j]!='[') --j;
                swap(s[i], s[j--]);
                ++ans;
            }
            t += (s[i]=='[' ? 1 : -1);
            ++i;
        }
        return ans;
    }
};