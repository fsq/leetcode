class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        for (int l=2; l<=4; ++l)
            for (int i=0; i+l<=a.size(); ++i)
                if (a[i]==a[i+l-1])
                    return a[i];
        return 0;
    }
};