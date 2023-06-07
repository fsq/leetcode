class Solution {
public:
    int unequalTriplets(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                if (a[i] != a[j])
                    for (int k=j+1; k<a.size(); ++k)
                        if (a[k] != a[i] && a[k] != a[j]) 
                            ++ans;
        return ans;
    }
};