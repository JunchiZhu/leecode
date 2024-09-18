//
// Created by 朱俊驰 on 9/17/24.
//

#include "../helper.h"
#include "../treenode.h"


TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(root==nullptr){return nullptr;}
    if(root->val<low){
        TreeNode* right = trimBST(root->right, low, high);
        return right;
    }
    if(root->val>high){
        TreeNode* left = trimBST(root->left, low, high);
        return left;
    }
    root->right=trimBST(root->right, low, high);
    root->left=trimBST(root->left, low, high);
    return root;
}

TreeNode* traversal(vector<int>& nums, int left, int right){
    if(left>right){return nullptr;}
    int mid_index = left + ((right - left) / 2);
    TreeNode* root = new TreeNode(nums[mid_index]);

    root->left=traversal(nums,left,mid_index-1);
    root->right=traversal(nums,mid_index+1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return traversal(nums, 0, nums.size()-1);
}

int prev_num;
void traversal(TreeNode* root){
    if(root== nullptr){ return;}
    traversal(root->right);
    prev_num += root->val;
    root->val=prev_num;
    traversal(root->left);
}

TreeNode* convertBST(TreeNode* root) {
    prev_num=0;
    traversal(root);
    return root;
}

int main(){
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(1);

    cout << "Test Case 1:" << endl;
    trimBST(root1, 1, 3);
    cout << endl;

    return 0;
}