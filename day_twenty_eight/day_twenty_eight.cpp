//
// Created by 朱俊驰 on 9/16/24.
//


#include "../helper.h"
#include "../treenode.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val>p->val and root->val>q->val){
        TreeNode* left = lowestCommonAncestor(root->left, p,q);
        if(left!= nullptr){
            return left;
        }
    }

    if(root->val<p->val and root->val<q->val){
        TreeNode* right= lowestCommonAncestor(root->right, p,q);
        if(right!= nullptr){
            return right;
        }
    }
    return root;
}



TreeNode* insertIntoBST_recursively(TreeNode* root, int val) {
    if(root == nullptr){
        auto* node = new TreeNode(val);
        return node;
    }
    if(root->val>val){
        root->left = insertIntoBST_recursively(root->left, val);
    }
    if(root->val<val){
        root->right = insertIntoBST_recursively(root->right, val);
    }
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root== nullptr){
        auto* node = new TreeNode(val);
        return node;
    }
    auto* node = new TreeNode(val);
    auto* cur = root;
    auto* parent = cur;
    while(cur!= nullptr){
        parent = cur;
        if(val>cur->val){
            cur = cur->right;
        }
        else if(val<cur->val){
            cur = cur->left;
        }
    }
    if (val < parent->val) parent->left = node;
    else parent->right = node;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root== nullptr){
        return nullptr;
    }
    if(root->val==key){
        if(root->left== nullptr and root->right== nullptr){
            delete root;
            return nullptr;
        }
        else if(root->right!= nullptr and root->left== nullptr){
            auto return_node = root->right;
            delete root;
            return return_node;
        }
        else if(root->left != nullptr and root->right== nullptr){
            auto return_node = root->left;
            delete root;
            return return_node;
        }
        else{
            TreeNode* cur = root->right;
            while(cur->left!= nullptr){
                cur=cur->left;
            }
            cur->left = root->left;
            auto return_node = root->right;
            delete root;

            return return_node;
        }
    }
    if(root->val<key){
        root->right = deleteNode(root->right, key);
    }
    if(root->val>key){
        root->left = deleteNode(root->left, key);
    }
    return root;
}

int main(){
    std::vector<int> treeNodes = {10, 5, 11, 3, 8, -1, 12, 1, -1, 6, 9}; // -1 represents NULL
    TreeNode* root = createTree(treeNodes, 0);
    TreeNode* p = new TreeNode(6);
    TreeNode* q = new TreeNode(9);
    cout<<lowestCommonAncestor(root,p,q)->val<<endl;

    std::vector<int> treeNodes2 = {4,2,7,1,3};
    TreeNode* root2 = createTree(treeNodes2, 0);
    matrix_printer(levelOrder<int>(insertIntoBST(root2,5)));



    return 0;

}