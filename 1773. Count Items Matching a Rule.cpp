class Solution {
public:
    int countMatches(vector<vector<string>>& a, string ruleKey, string ruleValue) {
        return count_if(a.begin(), a.end(), [&](vector<string>& s) {
            return (ruleKey=="type" && ruleValue==s[0] ||
                ruleKey=="color" && ruleValue==s[1] ||
                ruleKey=="name" && ruleValue==s[2]);
        });
    }
};