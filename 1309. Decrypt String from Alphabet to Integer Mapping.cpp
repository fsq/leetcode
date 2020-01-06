class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for (int i=0; i<s.size(); )
            if (i+2<s.size() && s[i+2]=='#') {
                ans.push_back(stoi(s.substr(i,2))-1+'a');
                i += 3;
            } else {
                ans.push_back(s[i]-'1'+'a');
                ++i;
            }
        return ans;
    }
};