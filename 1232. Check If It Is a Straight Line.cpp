class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        for (int i=0; i+2<a.size(); ++i) {
            int dx1=a[i+1][0]-a[i][0], dy1=a[i+1][1]-a[i][1];
            int dx2=a[i+2][0]-a[i+1][0], dy2=a[i+2][1]-a[i+1][1];
            if (dy2*dx1 != dy1*dx2) return false;
        }
        return true;
    }
};