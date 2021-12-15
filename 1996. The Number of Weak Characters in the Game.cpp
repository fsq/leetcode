class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int ans = 0, mx = -1;
        for (int i=a.size()-1; i>=0; --i) {
            if (mx > a[i][1])
                ++ans;
            if (i-1>=0 && a[i-1][0]!=a[i][0])
                for (int j=i; j<a.size() && a[j][0]==a[i][0]; ++j)
                    mx = max(mx, a[j][1]);
        }
        return ans;
    }
};