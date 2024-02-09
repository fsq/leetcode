class Solution {
public:
    string f2(const string& a, const string& b) {
        if (a.find(b) != string::npos) return a;
        for (int overlap=min(a.size(), b.size()); overlap>0; --overlap) {
            if (a.ends_with(b.substr(0, overlap))) 
                return a + b.substr(overlap);
        }
        return a + b;
    }

    string f3(const string& a, const string& b, const string& c) {
        return f2(f2(a,b), c);
    }

    string mn(const string& a, const string& b) {
        if (a.size() < b.size())
            return a;
        else if (a.size() > b.size())
            return b;
        else
            return min(a, b);
    }

    string minimumString(string a, string b, string c) {
        auto s1 = mn(f3(a,b,c), f3(a,c,b));
        auto s2 = mn(f3(b,a,c), f3(b,c,a));
        auto s3 = mn(f3(c,a,b), f3(c,b,a));
        return mn(s1, mn(s2, s3));
    }
};