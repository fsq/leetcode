class Solution {
public:
    int maxCoins(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0; i<a.size()/3; i+=1) ans += a[a.size()-2*(i+1)];
        return ans;
    }
};