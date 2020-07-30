class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        a.push_back(0);
        int ans = 0;
        for (int i=0; i+1<a.size(); ++i)
            if (a[i] > a[i+1])
                ans += a[i] - a[i+1];
        return ans;
    }
};