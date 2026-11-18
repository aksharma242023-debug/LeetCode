class Solution {
public:
  void traversal(TreeNode* root,vector<int>& ans){
        if(!root) return;
       
        traversal(root->left,ans);
        
        traversal(root->right,ans);
         ans.push_back(root->val);
     }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
         if(!root) return ans;
        traversal(root,ans);
        return ans;
    }
};