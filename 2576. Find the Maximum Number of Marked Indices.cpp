class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = 0;
        for (int i=0, j=n-n/2; j<a.size(); ++j) {
            if (2*a[i] <= a[j]) {
                ++i;
                ans += 2;
            }
        }
        return ans;
    }
};