class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& a) {
        long long ans = 0;
        for (int j,i=0; i<a.size(); i=j) {
            for (j=i+1; j<a.size() && a[j]!=a[j-1]; ++j);
            long long l = j - i;
            ans += (1+l) * l / 2;
        }
        return ans;
    }
};