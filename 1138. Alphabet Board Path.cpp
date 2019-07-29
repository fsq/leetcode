class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> map = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        vector<pair<int,int>> p(26);
        for (int i=0; i<6; ++i)
            for (int j=0; j<map[i].size(); ++j)
                p[map[i][j]-'a'] = {i, j};
        
        string ans;
        int x=0, y=0;
        for (auto c : target) {
            int tx, ty;
            tie(tx, ty) = p[c-'a'];
            for (int t=0; t<2; ++t) {
                while (x != tx) 
                    if (x > tx) 
                        ans += "U", --x;
                    else if (x < 4 || !y)
                        ans += "D", ++x;
                    else
                        break;
                while (y != ty)
                    if (y > ty)
                        ans += "L", --y;
                    else 
                        ans += "R", ++y;
            }
            ans += '!';
            x = tx, y = ty;
        }
        return ans;
    }
};