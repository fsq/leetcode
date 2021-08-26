class Solution {
public:
    bool canBeIncreasing(vector<int>& a) {
        int rm = 0;
        for (int i=1; i<a.size(); ++i)
            if (a[i]<=a[i-1]) {
                if (++rm>1) return false;
                if (i-2>=0 && a[i]>a[i-2] || i==1)
                    continue;
                else
                    a[i] = a[i-1];
            }
        return true;
    }
};