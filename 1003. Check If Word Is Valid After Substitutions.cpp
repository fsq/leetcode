class Solution {
public:
    bool isValid(string s) {
        vector<char> a;
        for (int i=0; i<s.size(); ++i) 
            if (s[i] == 'c') {
                if (! (a.size()>=2 && a[a.size()-1]=='b' && a[a.size()-2]=='a')) return false;
                a.pop_back();
                a.pop_back();
            } else 
                a.push_back(s[i]);
        return a.empty();   
    }
};