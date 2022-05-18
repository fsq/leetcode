class Solution {
public:
    int maxDistance(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=a.size()-1; j>i; --j)
                if (a[i] != a[j]) {
                    ans = max(ans, j-i);
                    break;
                }
        return ans;
    }
};