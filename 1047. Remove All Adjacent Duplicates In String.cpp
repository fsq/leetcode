class Solution {
public:
    string removeDuplicates(string s) {
        string x;
        for (auto c : s)
            if (x.empty() || c!=x.back())
                x.push_back(c);
            else 
                x.pop_back();
        return x;
    }
};