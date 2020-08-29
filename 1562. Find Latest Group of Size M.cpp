class Solution {
public:
    
    int findLatestStep(vector<int>& a, int m) {
        int n = a.size(), ans = -1;
        if (n == m) return n;
        vector<int> s(n+2);
        for (int i=0; i<a.size(); ++i) {
            int x = a[i];
            int l = s[x-1], r = s[x+1];
            s[x-l] = s[x+r] = l + r + 1;
            if (l== m || r==m) 
                ans = i;
        }
        return ans;
    }
};