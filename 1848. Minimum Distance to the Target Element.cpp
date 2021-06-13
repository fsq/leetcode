class Solution {
public:
    int getMinDistance(vector<int>& a, int target, int start) {
        int ans = -1;
        for (int i=0; i<a.size(); ++i)
            if (a[i] == target && (ans==-1 || abs(i-start)<abs(ans-start)))
                ans = i;
        return abs(ans - start);
    }
};