class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for (int j,i=0; i<s.size(); ++i) {
            int x = startPos[0], y = startPos[1];
            for (j=i; j<s.size(); ++j) {
                int dr = 0;
                if (s[j]=='R') dr = 1;
                else if (s[j]=='D') dr = 2;
                else if (s[j]=='L') dr = 3;
                x += dx[dr], y += dy[dr];
                if (x<0 || x>=n || y<0 || y>=n) break;
            }
            ans.push_back(j - i);
        }
        return ans;
    }
};