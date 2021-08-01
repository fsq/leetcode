class Solution {
public:
    
    void f(vector<vector<int>>& a) {
        auto b = a;
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a[0].size();++j)
                b[j][a.size()-i-1] = a[i][j];
        a = b;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i=0; i<4; ++i) {
            if (mat == target) return true;
            f(mat);        
        }
        return false;
    }
};