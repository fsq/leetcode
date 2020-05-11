class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1;
        for (auto x : target) {
            while (i<x) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++i;
            }
            ans.push_back("Push");
            ++i;
        }
        return ans;
    }
};