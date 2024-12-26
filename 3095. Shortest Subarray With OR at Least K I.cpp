class Solution {
public:
    int minimumSubarrayLength(vector<int>& a, int k) {
        int ans = INT_MAX;
        for (int i=0; i<a.size(); ++i) {
            int s = a[i], j;
            for (j=i+1; s<k && j<a.size(); ++j) s |= a[j];
            if (s >= k) ans = min(ans, j-i);
        }        
        return ans == INT_MAX ? -1 : ans;
    }
};