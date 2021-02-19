class Solution {
public:
    
    bool large(string& a, string& b, int i, int j) {
        while (i<a.size() && j<b.size() && a[i]==b[j])
            ++i, ++j;
        if (i==a.size()) return false;
        if (j==b.size()) return true;
        return a[i]>b[j];
    }
    
    string largestMerge(string a, string b) {
        string s;
        int i=0, j=0;
        while (i<a.size() || j<b.size()) 
            if (i==a.size()) {
                s.push_back(b[j++]);
            } else if (j==b.size()) {
                s.push_back(a[i++]);
            } else if (large(a, b, i, j)) {
                s.push_back(a[i++]);
            } else {
                s.push_back(b[j++]);
            }
        return s;
    }
};