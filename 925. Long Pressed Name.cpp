class Solution {
public:
    bool isLongPressedName(string a, string b) {
        if (a.size()>b.size()) return false;
        int i=0, j=0;
        while (i<a.size() && j<b.size()) {
            if (a[i]==b[j]) 
                ++i, ++j;
            else if (j>0 && b[j]==b[j-1])
                ++j;
            else
                return false;
        }
        return i==a.size();
    }
};