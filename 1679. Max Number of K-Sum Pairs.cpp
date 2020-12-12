class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0, j=a.size()-1; i<j; ) {
            while (i<j && a[i]+a[j]>k) --j;
            if (i<j && a[i]+a[j]==k) {
                ++ans;
                ++i, --j;
            } else 
                ++i;
        }
        return ans;
    }
};