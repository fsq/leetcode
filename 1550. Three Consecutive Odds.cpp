class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        for (int i=0; i+2<a.size(); ++i)
            if ((a[i] &1) && (a[i+1] & 1) && (a[i+2] & 1))
                return true;
        return false;
    }
};