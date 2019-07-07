class Solution {
public:
    string defangIPaddr(string s) {
        string ans;
        for (auto c : s)
            if (c=='.')
                ans += "[.]";
            else
                ans.push_back(c);
        return ans;
    }
};