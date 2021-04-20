class Solution {
public:
    int getMaximumConsecutive(vector<int>& a) {
        int r = 0;
        sort(a.begin(), a.end());
        for (auto x : a) 
            if (x > r+1) 
                return r+1;
            else 
                r += x;
        return r+1;
    }
};