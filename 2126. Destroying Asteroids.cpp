class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& a) {
        sort(a.begin(), a.end());
        for (auto x : a)
            if (x > mass)
                return false;
            else
                mass += x;
        return true;
    }
};