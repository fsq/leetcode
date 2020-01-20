class Solution {
public:
    int maximum69Number (int a) {
        string s = to_string(a);
        for (auto& x : s)
            if (x=='6') {
                x = '9';
                break;
            }
        return stoi(s);
    }
};