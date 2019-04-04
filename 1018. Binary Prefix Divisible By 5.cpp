class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int x = 0;
        vector<bool> ans;
        for (auto b : A) {
            x = x*2 + b;
            x %= 10;
            ans.push_back(x%5 == 0);
        }
        return ans;
    }
};