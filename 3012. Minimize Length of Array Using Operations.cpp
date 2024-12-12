class Solution {
public:
    int minimumArrayLength(vector<int>& a) {
        int mn = *min_element(a.begin(), a.end());
        int c=0;
        bool b = false;
        for (auto x : a) {
            if (x % mn != 0) {
                b = true;
                break;
            }
            if (x == mn) ++c;
        }
        if (b) {
            return 1;
        } else {
            return (c+1) / 2;
        }
    }
};