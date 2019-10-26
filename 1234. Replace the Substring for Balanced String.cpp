class Solution {
public:
    int balancedString(string s) {
        vector<int> count(128), extra(128);
        for (auto c : s) ++count[c];
        for (auto c : "QWER") {
            extra[c] = max<int>(0, count[c] - (int)s.size()/4);
            count[c] = 0;
        }
        
        int ans = s.size();
        for (int l=0,r=0; r<s.size(); ++r) {
            ++count[s[r]];
            while (l<=r && count[s[l]]>extra[s[l]]) 
                --count[s[l++]];
            if (count['Q']>=extra['Q'] && count['W']>=extra['W'] && count['E']>=extra['E'] && count['R']>=extra['R'])
                ans = min(ans, r-l+1);
        }
        return ans;
        
    }
};