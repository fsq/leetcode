class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        sort(a.begin(), a.end());
        int d = a[1] - a[0];
        for (int i=0; i+1<a.size(); ++i) 
            if (a[i+1]-a[i] != d)
                return false;
        return true;
    }
};