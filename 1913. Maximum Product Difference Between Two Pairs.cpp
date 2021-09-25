class Solution {
public:
    int maxProductDifference(vector<int>& a) {
        int a1=INT_MIN, a2=INT_MIN;
        int b1=INT_MAX, b2=INT_MAX;
        for (auto x : a) {
            if (x > a1)
                a2 = a1, a1 = x;
            else if (x > a2)
                a2 = x;
            
            if (x < b1)
                b2 = b1, b1 = x;
            else if (x < b2)
                b2 = x;
        }
        return a1*a2 - b1*b2;
    }
};