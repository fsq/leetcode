class Solution {
public:
    int countPoints(string rings) {
        vector<int> c(10);
        for (int i=0; i<rings.size(); i+=2) {
            char color = rings[i];
            int ind = rings[i+1] - '0';
            if (color == 'R')
                c[ind] |= 1;
            else if (color == 'G')
                c[ind] |= 2;
            else 
                c[ind] |= 4;
        }
        int ans = 0;
        for (auto x : c)
            if (x == 7)
                ++ans;
        return ans;
    }
};