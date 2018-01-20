class Solution {
public:
    
    // https://leetcode.com/problems/exclusive-time-of-functions/description/
    // O(n) time O(n) space using stack
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exe(n, 0);
        int prev=-1;    // previous start/end timestamp
        stack<int> stk; // id
        
        for (auto& log : logs) {
            log.push_back(':');
            istringstream in(log);
            
            string index;
            getline(in, index, ':');
            int id = stoi(index);
            
            string op;
            getline(in, op, ':');
            
            string time_stamp;
            getline(in, time_stamp, ':');
            int time = stoi(time_stamp);
            
            if (op.size()==5) {
                if (!stk.empty()) exe[stk.top()] += time - prev;
                stk.push(id);
                prev = time;
            } else {
                exe[id] += time - prev + 1;
                stk.pop();
                prev = ++time;
            }
        }
        return exe;
    }
};