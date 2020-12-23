class Solution {
public:
    string reformatNumber(string a) {
        vector<string> s;
        for (auto c : a)
            if (isdigit(c)) 
                if (s.empty())
                    s.push_back(string(1, c));
                else if (s.back().size()<3)
                    s.back() += c;
                else 
                    s.push_back(string(1, c));
        if (s.back().size()==1 && s.size()>1) {
            s.back() = s[s.size()-2][2] + s.back();
            s[s.size()-2].pop_back();
        }
        string ans;
        for (auto& x : s) {
            ans += std::move(x);
            ans += "-";
        }
        ans.pop_back();
        return ans;
    }
};