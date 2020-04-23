class Solution {
public:
    string reformat(string s) {
        int df = 0, n = s.size(), i = 0, j = n-1;
        for (int k=0; k<=j;)
            if (isdigit(s[k])) {
                swap(s[k], s[j--]);
                ++df;
            } else 
                --df, ++k;
        
        if (abs(df) > 1) return "";
        for (int i=df<0, j=n-1-(df>0); i<j; i+=2, j-=2) swap(s[i], s[j]);
        return s;
            
    }
};