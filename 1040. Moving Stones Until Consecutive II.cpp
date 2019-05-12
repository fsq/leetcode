class Solution {
public:
    int n;
    
    int minMove(vector<int>& a) {
        int ans = INT_MAX;
        for (int j=0,i=0; i<n; ++i) {
            while (j<n && a[j]<=a[i]+n-1) ++j;
            if (n-(j-i)==1 && a[j-1]==a[i]+n-2)
                ans = min(ans, 2);
            else 
                ans = min(ans, n-(j-i));
        }
        return ans;
    }
    
    int maxMove(vector<int>& a) {
        return (a[n-1]-a[0]+1-n) - min(a[1]-a[0]-1, a[n-1]-a[n-2]-1);
    }
    
    vector<int> numMovesStonesII(vector<int>& a) {
        n = a.size();
        sort(a.begin(), a.end());
        
        return {minMove(a), maxMove(a)};
    }
};