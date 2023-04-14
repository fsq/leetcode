class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> f(26);
        for (auto c : word) ++f[c-'a'];
        map<int, int> m;
        for (auto x : f)
            if (x)
                ++m[x];
        if (m.size()==1 && (m.begin()->first==1 || m.begin()->second==1)) return true;
        if (m.size() != 2) return false;
        auto it = next(m.begin());
        return (it->first==m.begin()->first+1 && it->second==1) || 
                (m.begin()->first==1 && m.begin()->second==1);
    }
};