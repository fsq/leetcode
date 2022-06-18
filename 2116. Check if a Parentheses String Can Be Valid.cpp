class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> left, free;
        for (int i=0; i<s.size(); ++i)
            if (locked[i]=='1') {
                if (s[i]==')') {
                    if (!left.empty()) {
                        int x = left.top(); left.pop();
                        locked[x] = locked[i] = '2';
                    } else if (!free.empty()) {
                        int x = free.top(); free.pop();
                        locked[x] = locked[i] = '2';
                    } else 
                        return false;
                } else {
                    left.push(i);
                }
            } else 
                free.push(i);
        free = stack<int>();
        for (int i=s.size()-1; i>=0; --i)
            if (locked[i] == '0')
                free.push(i);
            else if (locked[i] == '1') {
                if (free.empty())
                    return false;
                free.pop();
            }
        return free.size() % 2 == 0;
    }
};