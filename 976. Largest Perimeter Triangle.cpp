class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=a.size()-1; i>=2; --i) 
            if (a[i-1]+a[i-2]>a[i]) {
                ans = a[i-1] + a[i-2] + a[i];
                break;
            }
        return ans;
    }
};