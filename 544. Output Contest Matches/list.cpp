class Solution {
public:
    
    // https://leetcode.com/problems/output-contest-matches/description/
    // using list<string> to avoid copying strings.
    // time complexity: O(n + n/2+n/4+n/8+...) = O(n)
    // space complexity: O(n)
    
    string findContestMatch(int n) {
        vector<list<string>> lst;
        
        for (int i=1; i<=n; ++i)
            lst.push_back(list<string>(1, to_string(i)));
        
        for (auto it=n; it>1; it>>=1) {
            for (int i=0; i<it>>1; ++i) {
                lst[i].push_front("(");
                lst[i].push_back(",");
                lst[i].splice(lst[i].end(), lst[it-i-1]); // splice only takes constant time
                lst[i].push_back(")");
            }
        }
        string ans;
        for (auto& item : lst[0])
            ans += item;

        return ans;
    }
};