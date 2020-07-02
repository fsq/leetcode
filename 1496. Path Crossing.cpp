class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st = {"0,0"};
        int x = 0, y = 0;
        for (auto c : path) {
            if (c=='N')
                ++y;
            else if (c=='S')
                --y;
            else if (c=='W')
                --x;
            else 
                ++x;
            string w = to_string(x) + "," + to_string(y);
            if (st.count(w))
                return true;
            else
                st.insert(w);
        }
        return false;
    }
};