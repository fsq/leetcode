class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> m;
        for (auto c : word) ++m[c];
        vector<int> a;
        for (auto& pr : m) a.push_back(pr.second);
        sort(a.begin(), a.end());
        int ans = word.size();
        for (int i=0; i<a.size(); ++i) {
            int tot = 0;
            for (int j=i; j<a.size(); ++j)
                tot += min(a[i]+k, a[j]);
            ans = min<int>(ans, word.size()-tot);
        }
        return ans;
    }
};
