class Solution {
public:
    
    int A(int n, int m) {
        if (m==0) return 1;
        return A(n-1, m-1) * n;
    }
    
    int numDupDigitsAtMostN(int n) {
        ++n;
        string s = to_string(n);
        
        int ans = 0;
        for (int i=1; i<s.size(); ++i)
            ans += 9 * A(9, i-1);

        unordered_set<int> st;
        for (int i=0; i<s.size(); ++i) {
            
            for (int j=i==0 ? 1 : 0; j<s[i]-'0'; ++j)
                if (!st.count(j))
                    ans += A(9-st.size(), s.size()-i-1);
            if (st.count(s[i]-'0')) break;
            st.insert(s[i]-'0');
        }
        return n-1-ans;
    }
};