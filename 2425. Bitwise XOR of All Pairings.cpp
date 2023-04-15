class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int A=0, B=0;
        for (auto x : a) A^=x;
        for (auto y : b) B^=y;
        if (!(a.size() & 1)) B = 0;
        if (!(b.size() & 1)) A = 0;
        return A ^ B;
    }
};