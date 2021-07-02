class Solution {
public:
    string sortSentence(string s) {
        vector<string> ws(9);
        istringstream sin(s);
        for (string c; sin >> c; ) ws[c.back()-'1'] = c;
        string ans;
        for (int i=0; i<9; ++i) 
            if (ws[i].size())
                ans += ws[i].substr(0, ws[i].size()-1) + " ";
            else
                break;
        ans.pop_back();
        return ans;
    }
};