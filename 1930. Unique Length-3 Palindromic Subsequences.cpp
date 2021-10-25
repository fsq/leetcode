class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> tot(128), cur(128);
        for (auto c : s) ++tot[c];
        
        unordered_set<string> ans;
        for (auto c : s) {
            for (char x='a'; x<='z'; ++x)
                if (cur[x]>0 && tot[x]-cur[x]>(x==c ? 1 : 0)) {
                    ans.insert(string(1, c) + x);
                }
            ++cur[c];
        }
        
        return ans.size();
    }
};