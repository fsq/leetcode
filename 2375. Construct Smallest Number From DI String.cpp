class Solution {
public:
    string ans;

    bool dfs(vector<int>& vis, string& s, string& pt, int i) {
        if (i == pt.size()+1) {
            ans = s;
            return true;
        } else if (i==0) {
            for (int x=1; x<=pt.size()+1; ++x) {
                s = string(1, x + '0');
                vis[x] = true;
                if (dfs(vis, s, pt, i+1)) return true;
                vis[x] = false;
            }
        } else if (pt[i-1]=='I') {
            for (int x=s.back()-'0'+1; x<=pt.size()+1; ++x)
                if (!vis[x]) {
                    vis[x] = true;
                    s.push_back(x+'0');
                    if (dfs(vis, s, pt, i+1)) return true;
                    vis[x] = false;
                    s.pop_back();
                }
        } else {
            for (int x=1; x<=s.back()-'0'-1; ++x)
                if (!vis[x]) {
                    vis[x] = true;
                    s.push_back(x+'0');
                    if (dfs(vis, s, pt, i+1)) return true;
                    vis[x] = false;
                    s.pop_back();
                }
        }
        return false;
    }

    string smallestNumber(string pt) {
        vector<int> vis(10);
        string s;
        dfs(vis, s, pt, 0);
        return ans;
    }
};