class Solution {
public:
        
    string reverseParentheses(string s) {
        stack<int> stk;
        for (int i=0; i < s.size(); ++i) 
            if (s[i]=='(')
                stk.push(i);
            else if (s[i]==')') {
                int p = stk.top(); stk.pop();
                reverse(s.begin()+p+1, s.begin()+i);
            }
        string ans;
        for (auto c : s) 
            if (isalpha(c)) ans.push_back(c);
        return ans;
    }
};