class Solution {
public:
    int findChampion(vector<vector<int>>& a) {
        int n = a.size();
        for (int i=0; i<n; ++i) {
            if (accumulate(a[i].begin(), a[i].end(), 0) == n-1) {
                return i;
            }
        }
        return 0;
    }
};