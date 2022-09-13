class Solution {
public:
    int countCollisions(string directions) {
        string s;
        int ans = 0;
        for (auto c : directions) {
            if (c=='L' || c=='S') {
                while (!s.empty())
                    if (s.back()=='R') {
                        if (c=='L') {
                            ans += 2;
                            c = 'S';
                        } else {
                            ++ans;
                        }
                        s.pop_back();
                    } else if (s.back()=='S') {
                        if (c=='L') {
                            ++ans;
                            c = 'S';
                        }
                        break;
                    } else
                        break;
            }
            s.push_back(c);
        }
        return ans;
    }
};