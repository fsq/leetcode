class Solution {
public:
    int maximumGroups(vector<int>& a) {
        int n = a.size(), s, i;
        for (s=0, i=1; s+i<=a.size(); s+=i, ++i);
        return i-1;
    }
};