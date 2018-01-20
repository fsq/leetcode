class Solution {
public:
    
    // https://leetcode.com/problems/add-bold-tag-in-string/description/
    // using KMP
    // worst case O(m(l+n)) m=dict.size(), n=s.size(), l=avg length of words in dict
    // O(n+l) space
    
    vector<int> compute_next(const string& s) {
        int n = s.size();
        vector<int> f(n, 0);
        for (int i=1; i<n; ++i) {
            int j = f[i-1];
            while (j>0 && s[j]!=s[i]) j=f[j-1];
            f[i] = j + (s[i]==s[j]);
        }
        return f;
    }
    
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<bool> close(n, false);
        
        for (auto &word : dict) {
            auto next = compute_next(word);
            int i=0, j=0, pre_end = -1;
            while (i<n) {
                if (s[i]==word[j]) {
                    ++i;
                    ++j;
                } else if (j>0)
                    j = next[j-1];
                else 
                    ++i;
                if (j==word.size()) {
                    for (int it=max(pre_end+1, i-j); it<i; ++it) 
                        close[it] = true;
                    pre_end = i-1;
                    j = next[j-1];
                }
            }
        }
        
        string ans;
        for (int i=0; i<n; ++i) {
            if (close[i] && (i==0 || !close[i-1]))
                ans += "<b>";
            ans.push_back(s[i]);
            if (close[i] && (i==n-1 || !close[i+1]))
                ans += "</b>";
        }
        
        return ans;
    }
};