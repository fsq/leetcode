class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int d1 = -1, d2 = -1;
        for (int i=0; i<s1.size(); ++i)
            if (s1[i] != s2[i]) 
                if (d1==-1) 
                    d1 = i;
                else if (d2==-1)
                    d2 = i;
                else return false;
        if (d1==-1) return true;
        if (d2==-1) return false;
        swap(s1[d1], s1[d2]);
        return s1 == s2;
    }
};