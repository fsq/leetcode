class Solution {
public:
    int smallestRangeII(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int ans = a.back() - a.front();
        
        for (int i=0; i+1<a.size(); ++i) {
            int lt = min(a[i+1], a[0]+2*k);
            int rt = max(a.back(), a[i]+2*k);
            ans = min(ans, rt-lt);
        }
        return ans;
    }
};