class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int ans = 0;
        for (int i=0, j=0; i<a.size(); ++i) {
            while (j+1<b.size() && b[j+1]>=a[i]) ++j;
            if (b[j] >= a[i]) ans = max(ans, j-i);
        }
        return ans;
    }
};