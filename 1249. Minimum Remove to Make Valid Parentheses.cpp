class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int c = 0;
        string ans;
        for (auto x : s) 
            if (isalpha(x)) 
                ans.push_back(x);
            else {
                c += x=='(' ? 1 : -1;
                if (c >= 0) 
                    ans.push_back(x);
                else
                    ++c;
            }
        string t;
        for (int i=ans.size()-1; i>=0; --i)
            if (ans[i]=='(' && c>0)
                --c;
            else
                t.push_back(ans[i]);
        reverse(t.begin(), t.end());
        return t;
    }
};