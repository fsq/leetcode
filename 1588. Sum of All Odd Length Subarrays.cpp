class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            for (int s=0, j=i; j<a.size(); ++j) {
                s += a[j];
                if ((j-i+1) & 1) ans += s;
            }
        }
        return ans;
    }
};