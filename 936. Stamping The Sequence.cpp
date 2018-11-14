class Solution {
public:
    int n, m;
    
    bool myEqual(string::iterator l, string::iterator r, string::iterator p) {
        while (l!=r)
            if (*p=='?' || *l==*p) 
                ++l, ++p;
            else
                return false;
        return true;
    }
    
    bool fix(string& stamp, string& target, vector<int>& ans, int l, int r) {
        if (l>r) return true;
        
        for (int i=max(l-m+1, 0); i<=l && i+m<=n; ++i)
            if (myEqual(stamp.begin(), stamp.end(), target.begin()+i)) {
                ans.push_back(i);
                fill(target.begin()+i, target.begin()+i+stamp.size(), '?');
                return fix(stamp, target, ans, i+stamp.size(), r);
            }
        
        for (int j=max(0,r-m+1); j<=min(n-m, r); ++j) 
            if (myEqual(stamp.begin(), stamp.end(), target.begin()+j)) {
                ans.push_back(j);
                fill(target.begin()+j, target.begin()+j+stamp.size(), '?');
                return fix(stamp, target, ans, l, j-1);
            }
        
        return false;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int pre = 0;
        vector<int> ans;
        
        m = stamp.size();
        n = target.size();
        
        for (int i=0; i<n; )
            if (equal(stamp.begin(), stamp.end(), target.begin()+i)) {
                ans.push_back(i);
                fill(target.begin()+i, target.begin()+i+stamp.size(), '?');
                
                if (!fix(stamp, target, ans, pre, i-1)) return {};
                i = pre = i + stamp.size();
            } else 
                ++i;
        
        if (!fix(stamp,target, ans, pre, n-1) || ans.size()>10*target.size()) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};