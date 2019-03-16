class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int n = min(a.size(), b.size());
        int x = a[0], y = b[0], ansx = 0, ansy = 0, same = 0;
        
        for (int i=0; i<n; ++i) 
            same += a[i] == b[i];
        
        for (int i=1; i<n && ansx != INT_MAX; ++i) 
            if (a[i]!=x && b[i]!=x) 
                ansx = INT_MAX;
            else if (a[i]!=x && b[i]==x)
                ++ansx;
        
        for (int i=1; i<n && ansy != INT_MAX; ++i) 
            if (a[i]!=y && b[i]!=y) 
                ansy = INT_MAX;
            else if (b[i]!=y && a[i]==y)
                ++ansy;
        
        if (ansx != INT_MAX) ansx = min(ansx, n-same-ansx);
        if (ansy != INT_MAX) ansy = min(ansy, n-same-ansy);
        int ans = min(ansx, ansy);
        return ans==INT_MAX ? -1 : ans;
    }
};