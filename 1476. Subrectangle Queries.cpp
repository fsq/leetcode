class SubrectangleQueries {
public:
    vector<vector<int>> s, a;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        a = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        s.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for (int i=(int)s.size()-1; i>=0; --i)
            if (s[i][0]<=row && s[i][1]<=col && s[i][2]>=row && s[i][3]>=col)
                return s[i][4];
        return a[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */