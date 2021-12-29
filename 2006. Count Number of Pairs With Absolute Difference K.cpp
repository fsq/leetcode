class Solution {
public:
    int countKDifference(vector<int>& a, int k) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                if (abs(a[i]-a[j]) == k)
                    ++ans;
        return ans;
    }
};