class Solution {
public:
    
    // https://leetcode.com/problems/stickers-to-spell-word/description/
    // DFS with memo
    
    unordered_map<string, int> memo;
    
    int dfs(const vector<vector<int>>& stks, string& target) {
        if (target.empty()) return 0;
        if (memo.find(target)!=memo.end())
            return memo[target];
        
        int &ret = memo[target];
        ret = INT_MAX;
        
        vector<int> count(26, 0);
        for (auto c : target) ++count[c-'a'];
        
        for (auto& stk : stks) 
            if (stk[target[0]-'a']>0) {
                string rest;
                for (int i=0; i<26; ++i)
                    if (count[i]-stk[i]>0)
                        rest += string(count[i]-stk[i], 'a'+i);
                
                int ans = dfs(stks, rest);
                if (ans!=-1)
                    ret = min(ret, ans+1);
                if (ret==1)
                    break;
            }
        if (ret==INT_MAX)
            ret = -1;
        return ret;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> stks;
        for (auto& sticker : stickers) {
            vector<int> count(26, 0);
            for (auto c : sticker)
                ++count[c-'a'];
            stks.push_back(count);
        }
        
        sort(target.begin(), target.end());
        
        return dfs(stks, target);
    }
};