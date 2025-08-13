/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* rec(TreeNode* root){
        if(root==NULL)
            return NULL;

        TreeNode* temp=root->right;
        TreeNode* temp1=rec(root->left);
        TreeNode* temp2=rec(root->right);
        if(temp1){
            root->right = temp1;
            root->left = NULL;

            // go to end of leftFlattened
            TreeNode* curr = temp1;
            while(curr->right)
                curr = curr->right;
            curr->right =temp2;
        }
        return root;
    }
public:
    void flatten(TreeNode* root) {
        root=rec(root);
            }
};