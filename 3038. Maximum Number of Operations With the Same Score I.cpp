class Solution {
public:
    int maxOperations(vector<int>& a) {
        int ans = 1, s = a[0] + a[1];
        for (int i=2; i+1<a.size(); i+=2) {
            if (a[i]+a[i+1] != s) break;
            ++ans;
        }
        return ans;
    }
};