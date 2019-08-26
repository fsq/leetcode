class Solution {
public:
    
    struct Node {
        string name, dst;
        int time, val;
        Node(string name_, int time_, int val_, string dst_):
            name(std::move(name_)), time(time_), val(val_), dst(std::move(dst_)) {}
        
        string to_string() {
            return name + "," + std::to_string(time) + "," + std::to_string(val) + "," + dst;
        }
    };
    
    vector<string> invalidTransactions(vector<string>& ss) {
        vector<Node> a;
        unordered_set<int> ans;
        queue<int> q;
        unordered_map<string, unordered_set<int>> h;
        for (const auto& s : ss) {
            istringstream sin(s);
            string name, time, val, dst;
            getline(sin, name, ',');
            getline(sin, time, ',');
            getline(sin, val, ',');
            getline(sin, dst, ',');
            a.push_back(Node(name, stoi(time), stoi(val), dst));
        }
        
        sort(a.begin(), a.end(), [](Node& a, Node& b) {
            return a.time < b.time;
        });
        
        for (int id=0; id<a.size(); ++id) {
         
            while (q.size() && a[q.front()].time < a[id].time-60) {
                h[a[q.front()].name].erase(q.front());
                q.pop();
            }
            
            if (a[id].val > 1000) {
                ans.insert(id);
            }
            
            for (auto i : h[a[id].name])
                if (a[id].dst != a[i].dst) {
                    ans.insert(id);
                    ans.insert(i);
                }
            q.push(id);
            h[a[id].name].insert(id);
        }
        
        vector<string> ret;
        for (auto x : ans) ret.push_back(a[x].to_string());
        return ret;
    }
};