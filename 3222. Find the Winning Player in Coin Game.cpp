class Solution {
public:
    string winningPlayer(int x, int y) {
        int round = min(x, y/4);
        return (round & 1) ? "Alice" : "Bob";
    }
};