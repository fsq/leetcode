class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        int n = a.size(), k = n / 4;
        for (int i=0,j; i<n; i=j) {
            for (j=i; j<n && a[j]==a[i]; ++j);
            if (j-i > k) return a[i];
        }
        return -1;
    }
};