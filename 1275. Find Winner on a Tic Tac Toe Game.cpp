class Solution {
public:
    
    bool put(vector<vector<int>>& a, vector<int>& p, int x) {
        a[p[0]][p[1]] = x;
        if (a[p[0]][0]==a[p[0]][1] && a[p[0]][1]==a[p[0]][2]) return true;
        if (a[0][p[1]]==a[1][p[1]] && a[1][p[1]]==a[2][p[1]]) return true;
        if (a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]==x) return true;
        if (a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[1][1]==x) return true;
        return false;
    }
    
    string tictactoe(vector<vector<int>>& mv) {
        vector<vector<int>> a(3, vector<int>(3, -1));
        for (int i=0; i<mv.size(); ++i)
            if (put(a, mv[i], i&1))
                return (i&1) ? "B" : "A";
        return mv.size()==9 ? "Draw" : "Pending";
    }
};