class Solution {
public:
    // https://leetcode.com/problems/add-bold-tag-in-string/description/
    // Brute Force 
    // worst case O(nml) time, n=s.size(), m=dict.size(), l=avg length of words
    // O(n) space
    
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<bool> close(n, false);
        
        for (auto& word : dict) 
            for (int i=s.find(word, 0); i != string::npos; i=s.find(word, i+1))
                for (int j=0; j<word.size(); ++j)
                    close[i+j] = true;
        
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