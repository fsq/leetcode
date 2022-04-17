class Solution {
public:
    
    int f[41][41][2001];
    
    int dp(string& s1, string& s2, const int i, const int j, const int diff) {
        if (i==s1.size() && j==s2.size()) {
            return diff == 0;
        }
        if (diff==0 && (i==s1.size() || j==s2.size())) {
            return false;
        }
        int& ans = f[i][j][diff + 1000];
        if (ans != -1) return ans;
        
        if (diff==0 && islower(s1[i]) && islower(s2[j])) {
            return s1[i]==s2[j] ? dp(s1, s2, i+1, j+1, 0) : (ans=0);
        }

        if (diff>0 && j<s2.size() && islower(s2[j])) {
            return ans=dp(s1, s2, i, j+1, diff-1);
        } 
        
        if (diff>=0 && j<s2.size() && isdigit(s2[j]))
            for (int tj=j, v=0; tj<s2.size() && isdigit(s2[tj]); ++tj) {
                v = v*10 + (s2[tj]-'0');
                if (dp(s1, s2, i, tj+1, diff-v)) 
                    return ans=true;
            }
        
        if (diff<0 && i<s1.size() && islower(s1[i])) {
            return ans=dp(s1, s2, i+1, j, diff+1);
        } 
        
        if (diff<=0 && i<s1.size() && isdigit(s1[i]))
            for (int ti=i, v=0; ti<s1.size() && isdigit(s1[ti]); ++ti) {
                v = v*10 + (s1[ti]-'0');
                if (dp(s1, s2, ti+1, j, diff+v)) 
                    return ans=true;
            }
        
        return ans = 0;
    }
    
    bool possiblyEquals(string s1, string s2) {
        memset(f, -1, sizeof(f));
        return dp(s1, s2, 0, 0, 0);
    }
};