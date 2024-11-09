class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> a(n/2, vector<int>(26)), b = a;
        ++a[0][s[0]-'a'];
        ++b[0][s[n-1]-'a'];
        for (int i=1; i<n/2; ++i) {
            a[i] = a[i-1];
            ++a[i][s[i]-'a'];
            b[i] = b[i-1];
            ++b[i][s[n-i-1]-'a'];
        }
        vector<int> p(n/2+1);
        for (int i=n/2-1; i>=0; --i) {
            if (s[i] == s[n-i-1])
                p[i] = p[i+1] + 1;
            else
                p[i] = 0;
        }
        auto match = [&] (int i, int j) {
            if (i > j) return true;
            for (int c=0; c<26; ++c) {
                int x = a[j][c] - (i==0 ? 0 : a[i-1][c]);
                int y = b[j][c] - (i==0 ? 0 : b[i-1][c]);
                if (x != y) return false;
            }
            return true;
        };
        auto isPan = [&] (int i, int j) {
            return p[i] >= (j-i+1);
        };
        auto larger = [&] (vector<vector<int>>& a, int x1, int y1, vector<vector<int>>& b, int x2) {
            if (x2 < x1) return true;
            for (int c=0; c<26; ++c) {
                int c1 = a[y1][c] - (x1==0 ? 0 : a[x1-1][c]);
                int c2 = b[x2][c] - (x1==0 ? 0 : b[x1-1][c]);
                if (c1 < c2) {
                    return false;
                }
            }
            return true;
        };
        vector<bool> ans;
        for (auto& q : queries) {
            int x1 = q[0], y1 = q[1];
            int x2 = n-q[3]-1, y2 = n-q[2]-1;
            bool first = isPan(0, min(x1,x2)-1);
            bool last = isPan(max(y1,y2)+1, n/2-1);
            if (!first || !last) {
                ans.push_back(false);
                continue;
            }
            if (bool overlap = max(x1, x2) <= min(y1, y2); overlap) {
                bool lg = x1 > x2 ? larger(b, x2, y2, a, x1-1) : larger(a, x1, y1, b, x2-1);
                ans.push_back(match(min(x1,x2), max(y1,y2)) && lg);
            } else {
                int midPan = x2 > y1 ? isPan(y1+1, x2-1) : isPan(y2+1, x1-1);
                ans.push_back(match(x1,y1) && match(x2,y2) && midPan);
            }
        }
        return ans;
    }
};