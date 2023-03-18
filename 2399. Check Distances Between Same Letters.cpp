class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> pre(26, -1);
        for (int i=0; i<s.size(); ++i)
            if (pre[s[i]-'a'] != -1) {
                if (i-pre[s[i]-'a']!=distance[s[i]-'a']+1)
                    return false;
            } else {
                pre[s[i]-'a'] = i;
            }
        return true;
    }
};