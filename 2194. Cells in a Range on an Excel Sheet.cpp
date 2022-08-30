class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (char c=s[0]; c<=s[3]; ++c)
            for (char r=s[1]; r<=s[4]; ++r)
                ans.push_back(string(1, c) + string(1, r));
        return ans;
    }
};