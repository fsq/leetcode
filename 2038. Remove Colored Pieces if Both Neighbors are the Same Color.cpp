class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0, b=0;
        for (int i=0,j=0; i<colors.size(); ) {
            while (j<colors.size() && colors[j]==colors[i]) ++j;
            if (colors[i]=='A')
                a += max(0, j-i-2);
            else
                b += max(0, j-i-2);
            i = j;
        }
        return a > b;
    }
};