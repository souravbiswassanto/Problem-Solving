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
        
        int level[100000];
        memset(level, 0, sizeof level);
        
        function<void(TreeNode*, int)> recur =[&](TreeNode* poot, int lv){
            if(poot == NULL)return;
            if(poot != NULL and level[lv] == 0){
                level[lv] = poot->val;
            }
            if(poot->right != NULL)recur(poot->right, lv + 1);
            if(poot->left != NULL)recur(poot->left, lv + 1);
        };
        recur(root, 0);
        int cnt = 0;
        while(level[cnt]){
            v.push_back(level[cnt++]);
        }
        return v;
    }
};