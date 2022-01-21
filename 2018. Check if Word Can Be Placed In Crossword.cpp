class Solution {
public:
    
    bool ok(vector<vector<char>>& a, string& s) {
        int n = a.size(), m = a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j+s.size()<=m; ++j)
                if ((j==0 || a[i][j-1]=='#') && 
                    (j+s.size()==m || a[i][j+s.size()]=='#')) {
                    bool fit = true;
                    for (int k=0; k<s.size(); ++k)
                        if (!(a[i][j+k]==' ' || a[i][j+k]==s[k])) {
                            fit = false;
                            break;
                        }
                    if (fit) return true;
                }
        return false;
    }
        
    bool placeWordInCrossword(vector<vector<char>>& b1, string word) {
        int n = b1.size(), m = b1[0].size();
        vector<vector<char>> b2(m, vector<char>(n));
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                b2[j][i] = b1[i][j];
        if (ok(b1, word) || ok(b2, word)) return true;
        reverse(word.begin(), word.end());
        return ok(b1, word) || ok(b2, word);
    }
};