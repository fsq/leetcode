class Solution {
public:
    string decodeAtIndex(string s, int k) {
        --k;
        long long l = 0;
        for (auto x : s) 
            if (isalpha(x))
                ++l;
            else 
                l *= x - '0';
        
        for (int i=s.size()-1; i>=0; --i) 
            if (isalpha(s[i])) {
                if (l==k+1) return string(1, s[i]);
                --l;
            } else {
                l /= (long long)s[i] - '0';
                k %= l;
            }
        return "";
    }
};