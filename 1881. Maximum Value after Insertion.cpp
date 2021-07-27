class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0]=='-') {
            int i = 1;
            while (i<n.size() && n[i]<=x+'0') ++i;
            n.insert(n.begin()+i, x+'0');
        } else {
            int i = 0;
            while (i<n.size() && n[i]>=x+'0') ++i;
            n.insert(n.begin()+i, x+'0');
        }
        return n;
    }
};