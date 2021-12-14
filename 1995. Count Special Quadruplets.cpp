class Solution {
public:
    int countQuadruplets(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                for (int k=j+1; k<a.size(); ++k)
                    for (int l=k+1; l<a.size(); ++l) 
                        if (a[l] == a[i]+a[j]+a[k])
                            ++ans;
        return ans;
    }
};