class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int l=0, r=0;
        while (r<a.size())
            if (a[r] & 1)
                ++r;
            else 
                swap(a[l++], a[r++]);
        return a;
    }
};