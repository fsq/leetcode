class Solution {
public:
    int countGoodTriplets(vector<int>& ar, int a, int b, int c) {
        int ans = 0;
        for (int i=0; i<ar.size(); ++i)
            for (int j=i+1; j<ar.size(); ++j)
                if (abs(ar[i]-ar[j])<=a)
                    for (int k=j+1; k<ar.size(); ++k)
                        if (abs(ar[j]-ar[k])<=b && abs(ar[i]-ar[k])<=c)
                            ++ans;
        return ans;
    }
};