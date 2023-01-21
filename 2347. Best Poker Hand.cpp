class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> rc(14), sc(4);

        for (auto s : suits) 
            if (++sc[s-'a']==5)
                return "Flush";
        bool pair = false;
        for (auto r : ranks) {
            ++rc[r];
            if (rc[r]==3) return "Three of a Kind";
            if (rc[r]==2) pair = true;
        }
        return pair ? "Pair" : "High Card";
    }
};