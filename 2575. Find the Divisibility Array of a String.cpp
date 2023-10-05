class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long rm = 0;
        for (auto c : word) {
            rm = (rm*10 + (c-'0')) % m;
            ans.push_back(rm == 0); 
        }
        return ans;
    }
};