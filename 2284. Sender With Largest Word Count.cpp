class Solution {
public:
    string largestWordCount(vector<string>& m, vector<string>& senders) {
        unordered_map<string, int> cnt;
        for (int i=0; i<m.size(); ++i)
            cnt[senders[i]] += count(m[i].begin(), m[i].end(), ' ') + 1;
        int mx = 0;
        string ans;
        for (auto& pr : cnt) 
            if (pr.second > mx || pr.second==mx && pr.first>ans) {
                ans = pr.first;
                mx = pr.second;
            }
        return ans;
    }
};