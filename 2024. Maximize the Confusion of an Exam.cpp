class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans = 0;
        for (int c=0,l=0,r=0; l<s.size(); ++l) {
            while (r<s.size() && (c<k || c==k && s[r]=='T')) {
                if (s[r] != 'T') ++c;
                ++r;
            }
            ans = max(ans, r-l);
            if (s[l] != 'T') --c;
        }
        
        for (int c=0,l=0,r=0; l<s.size(); ++l) {
            while (r<s.size() && (c<k || c==k && s[r]=='F')) {
                if (s[r] != 'F') ++c;
                ++r;
            }
            ans = max(ans, r-l);
            if (s[l] != 'F') --c;
        }
        
        return ans;
    }
};