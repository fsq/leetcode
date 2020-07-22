class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> p(26);
        for (int i=0; i<s.size(); ++i) {
            int x = s[i] - 'a';
            if (p[x].empty())
                p[x] = {i, i};
            else
                p[x][1] = i;
        }
        int prer=-1;
        vector<string> ans;
        for (int i=0; i<s.size(); ++i) {
            int x = s[i] - 'a';
            if (p[x][0] == i) {
                int r = p[x][1];
                bool valid = true;
                for (int l=i; l<=r; ++l)
                    if (p[s[l]-'a'][0] < i) {
                        valid = false;
                        break;
                    } else 
                        r = max(r, p[s[l]-'a'][1]);
                if (!valid) continue;
                if (r <= prer) {
                    ans.pop_back();
                }
                ans.push_back(s.substr(i, r-i+1));
                prer = r;
            }
        }
        return ans;
    }
};