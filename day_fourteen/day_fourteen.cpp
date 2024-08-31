//
// Created by 朱俊驰 on 8/7/24.
//


#include <iostream>
#include <queue>
#include <stack>
#include "../treenode.h"

using namespace std;
// 前序：中左右
// 中序：左中右
// 后序：左右中

/// helper
void vector_printer(vector<int> &store){
    for(auto ele:store){
        cout<<ele<<" ";
    }
    cout<<endl;
}

void matrix_printer(vector<vector<int>> &store){
    for(auto ele:store){
        vector_printer(ele);
    }
}

/// tree traversal recursive methods
// 回溯第一步，确定终止条件
// 回溯第二步，确定单层逻辑
void pre_traversal(TreeNode* node, vector<int>& store){
    if(node == nullptr){
        return;
    }
    store.push_back(node->val);
    pre_traversal(node->left, store);
    pre_traversal(node->right, store);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> store;
    pre_traversal(root, store);
    return store;
}

void post_traversal(TreeNode* node, vector<int>& store){
    if(node == nullptr){return ;}
    post_traversal(node->left,store);
    post_traversal(node->right, store);
    store.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> store;
    post_traversal(root, store);
    return store;
}

void in_traversal(TreeNode* node, vector<int>& store){
    if(node == nullptr){return ;}
    in_traversal(node->left,store);
    store.push_back(node->val);
    in_traversal(node->right, store);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> store;
    in_traversal(root, store);
    return store;
}
/// tree traversal non-recursive methods
vector<int> preorderTraversal_none_recursive(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> my_stack;
    if(root!= nullptr){my_stack.push(root);}
    while (!my_stack.empty()){
        TreeNode *node =  my_stack.top();
        my_stack.pop();
        if(node->right!= nullptr){
            my_stack.push(node->right);
        }
        if(node->left!= nullptr){
            my_stack.push(node->left);
        }
        store.push_back(node->val);
    }

    return store;
}

/// tree traversal level order non-recursive
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> store;
    queue<TreeNode*> my_queue;
    if(root!= nullptr){
        my_queue.push(root);
    }
    while(!my_queue.empty()){
        vector<int> level_store;
        int size = my_queue.size();
        for(int i=0;i<size;++i){
            TreeNode *node = my_queue.front();
            my_queue.pop();
            level_store.push_back(node->val);
            if(node->left != nullptr){
                my_queue.push(node->left);
            }
            if(node->right != nullptr){
                my_queue.push(node->right);
            }
        }
        store.push_back(level_store);
    }
    return store;
}

vector<int> levelOrder_one_dimension_return(TreeNode* root) {
    vector<int> store;
    queue<TreeNode*> my_queue;
    if(root!= nullptr){
        my_queue.push(root);
    }
    while(!my_queue.empty()){
        TreeNode *node = my_queue.front();
        my_queue.pop();
        store.push_back(node->val);
        if(node->left != nullptr){
            my_queue.push(node->left);
        }
        if(node->right != nullptr){
            my_queue.push(node->right);
        }
    }
    return store;
}

/// tree traversal level order recursive
void level_order_traversal(TreeNode* node, vector<vector<int>> &store, int depth){
    if(node== nullptr){ return;}
    if(store.size()==depth){store.push_back(vector<int>{});};
    store[depth].push_back(node->val);
    level_order_traversal(node->left, store, depth+1);
    level_order_traversal(node->right, store, depth+1);
}

vector<vector<int>> levelOrderRecursive(TreeNode* root) {
    vector<vector<int>> store;
    int depth = 0;
    level_order_traversal(root, store, depth);
    return store;
}



int main(){
    TreeNode* left_tree = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    TreeNode* right_tree = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    TreeNode* root = new TreeNode(1, left_tree, right_tree);

    vector<int> result1 = preorderTraversal(root);
    vector_printer(result1);
    vector<int> result2 = preorderTraversal_none_recursive(root);
    vector_printer(result2);

    vector<vector<int>> result3 = levelOrderRecursive(root);
    matrix_printer(result3);

}

