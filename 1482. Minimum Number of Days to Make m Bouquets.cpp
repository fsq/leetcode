class Solution {
public:
    
    int count(vector<int>& a, int d, int k) {
        int ans = 0, now = 0;
        for (auto x : a) {
            if (x<=d) 
                ++now; 
            else 
                now = 0;
            if (now == k) {
                now = 0;
                ++ans;
            }
        }
        return ans;
    }
    
    int minDays(vector<int>& a, int m, int k) {
        if (m*k > a.size()) return -1;
        int l = 1, r = *max_element(a.begin(), a.end());
        while (l < r) {
            int mid = (l+r) >> 1;
            int d = count(a, mid, k);
            if (d < m) 
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};