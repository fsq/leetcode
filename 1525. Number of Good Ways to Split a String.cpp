class Solution {
public:
    int numSplits(string s) {
        vector<int> a(26), b=a;
        int ax=0, bx=0, ans=0;
        for (auto x : s) 
            if (++b[x-'a']==1)
                ++bx;
        for (int i=1; i<s.size(); ++i) {
            if (++a[s[i-1]-'a']==1)
                ++ax;
            if (--b[s[i-1]-'a']==0)
                --bx;
            ans += ax==bx;
        }
        return ans;
        
    }
};