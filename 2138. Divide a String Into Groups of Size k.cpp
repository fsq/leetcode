class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i=0; i<s.size(); i += k)
            if (i+k>s.size()) {
                string t = s.substr(i);
                t += string(k-t.size(), fill);
                ans.push_back(t);
            } else {
                ans.push_back(s.substr(i, k));
            }
        return ans;
    }
};