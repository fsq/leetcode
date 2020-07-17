class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                if (a[i]==a[j])
                    ++ans;
        return ans;
    }
};