class Solution {
public:
    string convert(string s, int r) {
        if (r==1) return s;
        string ans;
        for (int i=0; i<r; ++i) {
            for (int j=i; j<s.size(); j += 2*r-2) {
                ans.push_back(s[j]);
                if (i!=0 && i!=r-1 && j+2*(r-i-1)<s.size())
                    ans.push_back(s[j+2*(r-i-1)]);
            }
        }
        return ans;
    }
};