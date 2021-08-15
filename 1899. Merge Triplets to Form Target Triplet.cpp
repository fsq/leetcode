class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool c1=false,c2=false,c3=false;
        for (auto& a : triplets) {
            if (a[0]==target[0] && a[1]<=target[1] && a[2]<=target[2]) c1 = true;
            if (a[1]==target[1] && a[0]<=target[0] && a[2]<=target[2]) c2 = true;
            if (a[2]==target[2] && a[0]<=target[0] && a[1]<=target[1]) c3 = true;
            if (c1 && c2 && c3) return true;
        }
        return false;
    }
};