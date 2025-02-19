class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ind = 0;
        for (const auto& c : commands)
            if (c == "UP") {
                ind -= n;
            } else if (c == "DOWN") {
                ind += n;
            } else if (c == "RIGHT") {
                ++ind;
            } else {
                --ind;
            }
        return ind;
    }
};