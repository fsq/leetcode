class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> ind0, ind1;
        int l0=0, l1=0;
        for (int i=0; i<words.size(); ++i)
            if (groups[i] == 0) {
                if (l1 + words[i].size() > l0) {
                    l0 = l1 + words[i].size();
                    ind0 = ind1;
                    ind0.push_back(i);
                }
            } else {
                if (l0 + words[i].size() > l1) {
                    l1 = l0 + words[i].size();
                    ind1 = ind0;
                    ind1.push_back(i);
                }
            }
        vector<string> ans;
        if (l1 > l0) {
            ind0.swap(ind1);
        }
        for (auto i : ind0) ans.push_back(words[i]);
        return ans;
    }
};