class Solution {
public:
    int findMax(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0,j; i<a.size(); i=j) {
            for (j=i+1; j<a.size() && a[j]==a[j-1]+1; ++j);
            ans = max(ans, a[j-1]-a[i]+2);
        }
        return ans;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& a, vector<int>& b) {
        int x = findMax(a);
        int y = findMax(b);
        int s = min(x, y);
        return s * s;
    }
};