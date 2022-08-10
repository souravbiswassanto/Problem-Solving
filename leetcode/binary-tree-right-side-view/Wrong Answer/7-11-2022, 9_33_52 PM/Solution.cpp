// https://leetcode.com/problems/binary-tree-right-side-view

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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        TreeNode* vat = new TreeNode(0, NULL, root);
        
        int check = 0;
        while(1){
            check = 0;
            if(vat->right != NULL){
                vat = vat->right;
                v.push_back(vat->val); check = 1;
            }
            else if(vat->left != NULL){
                vat = vat->left;
                v.push_back(vat->val); check = 1;
            }
            if(!check)break;
        }
        return v;
    }
};