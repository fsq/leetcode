class Solution {
public:
    vector<long long> pan;
    
    string dfs(int len, int r, bool first) {
        if (len == 0) return "";
        if (len == 1) return (r+first) > 9 ? "-1" : string(1, '0'+r+first);
        long long c = r / pan[len-2] + first;
        if (c > 9) return "-1";
        r = r % pan[len-2];
        return string(1, c+'0') + dfs(len-2, r, false) + string(1, c+'0');
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        pan.resize(intLength+1);
        pan[0] = 1;
        pan[1] = 10;
        for (int i=2; i<=intLength; ++i) 
            pan[i] = 10 * pan[i-2];
        vector<long long> ans;
        for (auto x : queries) {
            string n = dfs(intLength, x-1, true);
            ans.push_back(stoll(n));
        }
        return ans;
    }
};