class Solution {
public:
    bool isBoomerang(vector<vector<int>>& a) {
        return ! ((a[2][1]-a[1][1])*(a[1][0]-a[0][0]) == (a[1][1]-a[0][1])*(a[2][0]-a[1][0]));
    }
};