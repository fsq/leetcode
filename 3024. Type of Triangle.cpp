class Solution {
public:
    string triangleType(vector<int>& a) {
        sort(a.begin(), a.end());
        if (a[0]+a[1] <= a[2]) return "none";
        if (a[0] == a[2]) return "equilateral";
        if (a[0]==a[1] || a[1]==a[2]) return "isosceles";
        return "scalene";
    }
};