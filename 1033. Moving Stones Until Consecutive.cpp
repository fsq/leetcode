class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        
        vector<int> ans(2);
        if (s[2]==s[0]+2)
            ans[0] = 0;
        else if (s[1]-s[0]==2 || s[2]-s[1]==2)
            ans[0] = 1;
        else
            ans[0] = min(1, s[1]-s[0]-1) + min(1, s[2]-s[1]-1);
        ans[1] = s[1]-s[0]-1 + s[2]-s[1]-1;
        return ans;
    }
};