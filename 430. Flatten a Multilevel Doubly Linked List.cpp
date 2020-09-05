/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* dfs(Node* rt, Node* now) {
        if (!now) return rt;
        Node* cur = new Node();
        cur->val = now->val;
        cur->prev = rt;
        cur->next = cur->child = NULL;
        rt->next = cur;

        rt = dfs(cur, now->child);
        return dfs(rt, now->next);
    }
    
    Node* flatten(Node* head) {
        if (!head) return NULL;
        Node *rt = new Node();
        dfs(rt, head);
        auto ans = rt->next;
        ans->prev = NULL;
        delete rt;
        return ans;
    }
};