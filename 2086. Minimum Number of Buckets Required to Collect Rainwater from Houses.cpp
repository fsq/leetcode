class Solution {
public:
    int minimumBuckets(string s) {
        int ans = 0;
        for (int i=0; i<s.size(); ++i)
            if (s[i]=='H')
                if (i>0 && s[i-1]=='B')
                    continue;
                else if (i+1<s.size() && s[i+1]=='.')
                    s[i+1] = 'B', ++ans;
                else if (i>0 && s[i-1]=='.') {
                    ++ans;
                    continue;  
                } else
                    return -1;
        return ans;
    }
};