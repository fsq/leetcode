class Solution {
public:
    int bestClosingTime(string s) {
        int cy = count(s.begin(), s.end(), 'Y');
        int penalty = cy, ans = 0, pre = 0;
        for (int i=0; i<s.size(); ++i) {
            pre += s[i]=='Y';
            int p = (i+1)-pre + cy - pre;
            if (p < penalty) {
                penalty = p;
                ans = i + 1;
            }
        }
        return ans;
    }
};