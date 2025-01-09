class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) {
        int ans = INT_MIN;
        for (int i=0; i<k; ++i) {
            int s = 0;
            for (int j=i; j<a.size(); j+=k) {
                s = max(s + a[j], a[j]);
            }
            ans = max(ans, s);
        }
        return ans;
    }
};