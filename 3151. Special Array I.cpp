class Solution {
public:
    bool isArraySpecial(vector<int>& a) {
        for (int i=0; i+1<a.size(); ++i)
            if (!((a[i] ^ a[i+1]) & 1))
                return false;
        return true;
    }
};