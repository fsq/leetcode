class Solution {
public:
    
    int n;
    
    vector<int> decode(vector<int>& c) {
        int n = c.size()+1, s = 0, cs = c[0];
        
        for (int i=1; i<c.size(); ++i) {
            c[i] ^= c[i-1];
            cs ^= c[i];
            s ^= i;
        }
        s = s ^ c.size() ^ n;
        // c[i] = a[0] ^ a[i+1];
        // c[0] ^...^ c[n-2] = a[1] ^...^ a[n-1]
        vector<int> ans(n);
        ans[0] = s ^ cs;
        for (int i=0; i<c.size(); ++i)
            ans[i+1] = ans[0] ^ c[i];
        return ans;
    }
};