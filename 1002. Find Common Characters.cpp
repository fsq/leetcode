class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        int n = a.size();
        vector<unordered_map<char, int>> m(n);
        
        for (int i=0; i<n; ++i)
            for (auto c : a[i])
                ++m[i][c];
        
        vector<string> ans;
        for (char c='a'; c<='z'; ++c) {
            int f = INT_MAX;
            for (auto& mp : m)
                f = min(f, mp[c]);
            
            while (f--)
                ans.push_back(string(1, c));
                
        }
        return ans;
        
    }
};