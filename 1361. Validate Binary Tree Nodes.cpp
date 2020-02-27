class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> ind(n);
        for (auto x : leftChild)  
            if (x != -1)
                ++ind[x];
        for (auto x : rightChild)
            if (x != -1)
                ++ind[x];
        bool root = false;
        for (auto x : ind)
            if (x == 0) {
                if (root) return false;
                root = true;
            } else if (x > 1)
                return false;
        return root;
    }
};