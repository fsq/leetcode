class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();
        vector<int> ans;
        int a=0, b=0;
        for (auto c : s)
            if (c=='(') {
                if (a > b) {
                    ++b; ans.push_back(1);
                } else {
                    ++a; ans.push_back(0);
                }
            } else if (a > b) {
                --a; ans.push_back(0);
            } else {
                --b; ans.push_back(1);
            }
        return ans;
    }
};