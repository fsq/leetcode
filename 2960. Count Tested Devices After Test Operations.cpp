class Solution {
public:
    int countTestedDevices(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            if (a[i] > 0) {
                ++ans;
                for (int j=i+1; j<a.size(); ++j) --a[j];
            }
        }
        return ans;
    }
};