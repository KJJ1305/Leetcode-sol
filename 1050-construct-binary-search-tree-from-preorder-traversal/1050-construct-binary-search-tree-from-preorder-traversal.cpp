class Solution {
    int i = 0;
    TreeNode* build(vector<int>& pre, int bound) {
        if (i == pre.size() || pre[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = build(pre, root->val);
        root->right = build(pre, bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};
