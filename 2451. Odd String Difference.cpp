class Solution {
public:

    vector<int> f(string& s) {
        vector<int> a;
        for (int i=0; i+1<s.size(); ++i) a.push_back(s[i+1]-s[i]);
        return a;
    }

    string oddString(vector<string>& words) {
        auto a = f(words[0]);
        auto b = f(words[1]);
        if (a != b) {
            auto c = f(words[2]);
            return a==c ? words[1] : words[0];
        }
        for (int i=2; i<words.size(); ++i)
            if (f(words[i]) != a) 
                return words[i];
        return "";
    }
};