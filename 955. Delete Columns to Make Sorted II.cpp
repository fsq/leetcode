class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n = a.size();
        if (n==1) return 0;
        
        int del = 0;
        vector<int> eq(n, 1);
        bool delthis = false;
        
        for (int j=0; j<a[0].size(); delthis=false, ++j)  {
            for (int i=0; i+1<n; ++i)
                if (a[i+1][j]<a[i][j] && eq[i]) {
                    ++del;
                    delthis = true;
                    break;
                }
            if (!delthis)
                for (int i=0; i+1<n; ++i)
                    eq[i] = eq[i] && (a[i][j]==a[i+1][j]);
        }
            
        return del;
    }
};