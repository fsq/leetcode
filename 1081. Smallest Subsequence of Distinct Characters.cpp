class Solution {
public:
    string smallestSubsequence(string a) {
        vector<int> left(129), vis(129);
        for (auto c : a) ++left[c];
        string ans;
        for (auto c : a) {
            if (!vis[c]) {
                while (!ans.empty() && ans.back()>c && left[ans.back()]) {
                    vis[ans.back()] = false;
                    ans.pop_back();
                }
                ans.push_back(c);
                vis[c] = true;
            }
            --left[c];
        }
        return ans;
    }
};