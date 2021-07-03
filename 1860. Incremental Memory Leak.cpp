class Solution {
public:
    vector<int> memLeak(int a, int b) {
        int x = 1;
        while (a>=x || b>=x) {
            if (a >= b)
                a -= x;
            else 
                b -= x;
            ++x;
        }
        return {x, a, b};
    }
};
