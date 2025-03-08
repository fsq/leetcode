class Solution {
public:

    bool eq(int x, int y) {
        string s = to_string(x), t = to_string(y);
        if (s.size() < t.size())
            s = string(t.size()-s.size(), '0') + s;
        else if (s.size() > t.size())
            t = string(s.size()-t.size(), '0') + t;
        vector<int> df;
        for (int i=0; i<s.size(); ++i)
            if (s[i] != t[i]) {
                if (df.size() == 2) return false;
                df.push_back(i);
            }
        return df.empty() || df.size()==2 && s[df[0]]==t[df[1]] && s[df[1]]==t[df[0]];
    }

    int countPairs(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                if (eq(a[i], a[j]))
                    ++ans;
        return ans;
    }
};