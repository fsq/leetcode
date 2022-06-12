class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        for (int i=0, j=0; i<s.size(); ++i) {
            if (j<spaces.size() && i==spaces[j]) {
                ans.push_back(' ');
                ++j;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};