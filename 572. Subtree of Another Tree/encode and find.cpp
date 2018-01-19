/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // https://leetcode.com/problems/subtree-of-another-tree/description/
    // O(nm) time O(n+m) space solution
    // encode each tree to a string, and do pattern matching
    // string.find uses a bruteforce O(nm) algorithm. 
    // We can change to KMP for better performance
    
    void dfs(const TreeNode* node, ostringstream& out) {
        if (!node)
            out << '#';
        else {
            // use only 4 chars to encode an integer
            // gives shorter string when val is large
            char buf[4];
            memcpy(buf, &(node->val), sizeof(int));
            for (int i=0; i<3; ++i) out << buf[i];
            out << ' ';
            dfs(node->left, out);
            out << ' ';
            dfs(node->right, out);
        }
    }
    
    string encode(const TreeNode* node) {
        ostringstream out;
        dfs(node, out);
        return out.str();
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string encode_s = encode(s);
        string encode_t = encode(t);
        return encode_s.find(encode_t) != string::npos;
    }
};