class Solution {
public:
    int minimumCost(string a, vector<string>& words, vector<int>& costs) {
        vector<int> f(a.size()+1, INT_MAX);
        f[0] = 0;
        for (int i=1; i<=a.size(); ++i) {
            for (int j=0; j<words.size(); ++j)
                if (i>=words[j].size() && f[i-words[j].size()]!=INT_MAX 
                        && equal(words[j].begin(), words[j].end(), a.begin()+i-words[j].size())) {
                            f[i] = min(f[i], f[i-words[j].size()] + costs[j]);
                        }
        }
        return f.back()==INT_MAX ? -1 : f.back();
    }
};