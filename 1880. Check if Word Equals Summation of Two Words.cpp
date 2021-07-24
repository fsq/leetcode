class Solution {
public:
    
    int f(const string& s) {
        string t;
        for (auto c : s) t += '0' + c - 'a';
        return stoi(t);
    }
    
    bool isSumEqual(string a, string b, string c) {
        return f(a) + f(b) == f(c);
    }
};