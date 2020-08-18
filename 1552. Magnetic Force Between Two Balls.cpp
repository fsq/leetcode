class Solution {
public:
    
    int f(vector<int>& a, int d) {
        int ans = 0, pre = INT_MIN;
        for (auto x : a)
            if (x >= pre+d) {
                ++ans;
                pre = x;
            }
        return ans;
    }
    
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int l = 0, r = (a.back()-a.front())/(m-1);
        while (l < r) {
            int mid = (l+r+1) >> 1;
            int put = f(a, mid);
            if (put < m)
                r = mid - 1;
            else 
                l = mid;
        }
        return l;
    }
};