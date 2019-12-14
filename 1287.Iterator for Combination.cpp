class CombinationIterator {
public:
    vector<int> a;
    string s;
    int l;
    
    CombinationIterator(string characters, int len) {
        s = characters;
        l = len;
        a.resize(len);
        iota(a.begin(), a.end(), 0);
        --a.back();
    }
    
    string next() {
        if (a.back() != s.size()-1) {
            ++a.back();
        } else {
            int i;
            for (i=l-1; i>=0; --i)
                if (a[i]+1 + (l-i) <= s.size()) break;
            ++a[i];
            for (++i; i<l; ++i) a[i] = a[i-1] + 1;
        }
        string ans;
        for (auto x : a) ans.push_back(s[x]);
        return ans;
    }
    
    bool hasNext() {
        return !(a[0]==s.size()-l && a.back()==s.size()-1);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */