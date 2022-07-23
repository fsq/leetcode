class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long b = 1, h = 0;
        for (int i=s.size()-k; i<s.size(); ++i) {
            h = (h + (s[i]-'a'+1) * b) % modulo;
            if (i+1<s.size()) b = (b * power) % modulo;
        }
        int ans = 0;
        if (h == hashValue) ans = s.size() - k;
        for (int i=(int)s.size()-k-1; i>=0; --i) {
            h = ((h - (s[i+k]-'a'+1)*b) % modulo + modulo) % modulo;
            h = (h * power) % modulo;
            h = (h + (s[i]-'a'+1)) % modulo;
            if (h == hashValue) ans = i;
        }
        
        return s.substr(ans, k);
    }
};