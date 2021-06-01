class Solution {
public:
    int maxIceCream(vector<int>& a, int coins) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0; i<a.size() && coins>=a[i]; ++i) {
            ++ans;
            coins -= a[i];
        }
        return ans;
    }
};