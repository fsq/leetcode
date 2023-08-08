class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> a(26), b(26);
        int c1=0, c2=0;
        for (auto c : word1) 
            if (++a[c-'a']==1) {
                ++c1;
            }
        for (auto c : word2) 
            if (++b[c-'a']==1) {
                ++c2;
            }
        for (int i=0; i<26; ++i)
            for (int j=0; j<26; ++j)
                if (a[i]>0 && b[j]>0) {
                    int t1 = c1, t2 = c2;
                    if (i != j) {
                        if (a[i]==1) --t1;
                        if (a[j]==0) ++t1;
                        if (b[j]==1) --t2;
                        if (b[i]==0) ++t2;
                    }
                    if (t1 == t2) return true;
                }
        return false;
    }
};