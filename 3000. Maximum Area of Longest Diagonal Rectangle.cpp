class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int dig=0, area=0;
        for (auto& a : dim) {
            int d = a[0]*a[0] + a[1]*a[1];
            int ar = a[0] * a[1];
            if (d>dig || d==dig && ar>area) {
                dig = d;
                area = ar;
            }
        }
        return area;
    }
};