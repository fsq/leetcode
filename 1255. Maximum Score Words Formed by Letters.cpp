class Solution {
public:
    
    int ans = 0;
    
    void dfs(const vector<unordered_map<char,int>>& wc, unordered_map<char, int>& lc, vector<int>& score, int sum, int i) {
        if (i==wc.size())
            ans = max(ans, sum);
        else {
            dfs(wc, lc, score, sum, i+1);
            if (all_of(wc[i].begin(), wc[i].end(), [&](auto& pr) {
                return pr.second <= lc[pr.first];
            })) {
                for (auto& pr : wc[i]) {
                    lc[pr.first] -= pr.second;
                    sum += pr.second * score[pr.first-'a'];
                }
                dfs(wc, lc, score, sum, i+1);
                for (auto& pr : wc[i]) {
                    lc[pr.first] += pr.second;
                    sum -= pr.second * score[pr.first-'a'];
                }
            }
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<unordered_map<char,int>> wc(words.size());
        for (int i=0; i<words.size(); ++i) 
            for (auto c : words[i])
                ++wc[i][c];
        unordered_map<char, int> lc;
        for (auto& c : letters)
            ++lc[c];
        
        dfs(wc, lc, score, 0, 0);
        return ans;
    }
};