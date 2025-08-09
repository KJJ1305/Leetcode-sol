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
    TreeNode* insert(TreeNode *root,int val){
        TreeNode* temp=new TreeNode(val);
        if(root==NULL){
            return temp;
        }
        if(val>root->val){
            root->right=insert(root->right,val);
        }
        else{
            root->left=insert(root->left,val);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root;
        for(int i=0;i<preorder.size();i++){
            root=insert(root,preorder[i]);
        }
        return root;
    }
};