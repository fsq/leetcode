class Solution {
public:

    long long find(vector<int>& b1, vector<int>& t1, vector<int>& b2, vector<int>& t2) {
        int x_left = max(b1[0], b2[0]), x_right = min(t1[0], t2[0]);
        int y_btm = max(b1[1], b2[1]), y_top = min(t1[1], t2[1]);
        if (x_left > x_right || y_btm > y_top) return 0;
        int side = min(x_right-x_left, y_top-y_btm);
        return (long long)side * side;
    }

    long long largestSquareArea(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        long long ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                ans = max(ans, find(a[i], b[i], a[j], b[j]));
        return ans;
    }
};