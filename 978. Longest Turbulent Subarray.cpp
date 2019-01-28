class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int ans = 1;
        for (int j,i=0; i+1<a.size(); ) 
            if (a[i]==a[i+1])
                ++i;
            else {
                bool inc = a[i+1] > a[i];
                for (j=i+2; j<a.size(); ++j)
                    if (a[j]==a[j-1] || (inc==a[j]>a[j-1]))
                        break;
                    else 
                        inc = !inc;
                ans = max(ans, j-i);
                i = j-1;
            }
        return ans;
    }
};