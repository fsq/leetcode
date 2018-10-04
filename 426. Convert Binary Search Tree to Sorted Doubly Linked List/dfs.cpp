/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *pre, *head;
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        pre = head = NULL;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    
    void dfs(Node* x) {
        if (!x) return;
        dfs(x->left);
        if (!head) 
            head = x;
        else {
            pre->right = x;
            x->left = pre;
        }
        pre = x;
        dfs(x->right);
    }
};