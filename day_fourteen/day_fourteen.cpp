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
        TreeNode* node = my_stack.top();
        my_stack.pop();
        if(node->right){
            my_stack.push(node->right);
        }
        if(node->left){
            my_stack.push(node->left);
        }
        store.push_back(node->val);
    }
    return store;
}

vector<int> inorderTraversal_none_recursive(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> my_stack;
    TreeNode* cur = root;
    while((cur != nullptr) or !my_stack.empty())
        if(cur != nullptr){
            my_stack.push(cur);
            cur = cur->left;
        } else{
            TreeNode* node = my_stack.top();
            my_stack.pop();
            store.push_back(node->val);
            cur=cur->right;
        }

    return store;
}

vector<int> postorderTraversal_none_recursive(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> my_stack;
    if(root){
        my_stack.push(root);
    }
    while(!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();

        if(node->left){
            my_stack.push(node->left);
        }
        if(node->right){
            my_stack.push(node->right);
        }
        store.push_back(node->val);
    }
    reverse(store.begin(), store.end());
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

vector<vector<int>> levelOrder_test(TreeNode* root) {
    vector<vector<int>> store;
    queue<TreeNode*> my_queue;
    if(root){
        my_queue.push(root);
    }
    while (!my_queue.empty()){
        vector<int> temp;
        int size = my_queue.size();
        for(int i=0;i<size;++i){
            TreeNode* node = my_queue.front();
            my_queue.pop();
            temp.push_back(node->val);
            if(node->left){
                my_queue.push(node->left);
            }
            if(node->right){
                my_queue.push(node->right);
            }
        }
        store.push_back(temp);
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

vector<int> levelOrder_test1(TreeNode* root) {
    vector<int> store;
    queue<TreeNode*> my_queue;
    if(root){
        my_queue.push(root);
    }
    while(!my_queue.empty()){

        TreeNode* node = my_queue.front();
        my_queue.pop();
        store.push_back(node->val);

        if(node->left){
            my_queue.push(node->left);
        }
        if(node->right){
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
void level_order_traversal_1(TreeNode* cur, vector<vector<int>> &store, int depth){
    if(cur== nullptr){
        return;
    }
    if(store.size()==depth){
        store.push_back(vector<int>{});
    }
    store[depth].push_back(cur->val);
    level_order_traversal_1(cur->left,store,depth+1);
    level_order_traversal_1(cur->right,store,depth+1);

}

vector<vector<int>> levelOrderRecursive_test(TreeNode* root) {
    vector<vector<int>> store;
    int depth = 0;
    level_order_traversal_1(root, store, depth);
    return store;
}

//      1
//    2   3
//  4  5 6  7
// 前序 中左右
// 后序 左右中
// 中序 左中右
// 中右左 -> 1376254 -> 4526731

// 1245367
vector<int> preorderTraversal_test2(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> my_stack;
    if(root){
        my_stack.push(root);
    }
    while (!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();
        store.push_back(node->val);
        if(node->right){
            my_stack.push(node->right);
        }
        if(node->left){
            my_stack.push(node->left);
        }
    }
    return store;
}

// 4526731
vector<int> postorderTraversal_test2(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> my_stack;
    if(root){
        my_stack.push(root);
    }
    while (!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();
        store.push_back(node->val);
        if(node->left){
            my_stack.push(node->left);
        }
        if(node->right){
            my_stack.push(node->right);
        }
    }
    reverse(store.begin(),store.end());
    return store;
}

// 4251637
//      1
//    2   3
//  4  5 6  7
vector<int> inorderTraversal_test2(TreeNode* root) {
    stack<TreeNode*> my_stack;
    TreeNode* cur = root;
    vector<int> store;
    while(cur!= nullptr || !my_stack.empty()){
        if(cur!= nullptr){
            my_stack.push(cur);
            cur=cur->left;
        } else{
            cur = my_stack.top();
            my_stack.pop();
            store.push_back(cur->val);
            cur = cur->right;
        }
    }
    return store;
}


int main(){
    TreeNode* left_tree = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    TreeNode* right_tree = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    TreeNode* root = new TreeNode(1, left_tree, right_tree);

    vector<int> pre_result1 = preorderTraversal(root);
    vector_printer(pre_result1);
    vector<int> pre_result2 = preorderTraversal_test2(root);
    vector_printer(pre_result2);

    vector<int> post_result1 = postorderTraversal(root);
    vector_printer(post_result1);
    vector<int> post_result2 = postorderTraversal_test2(root);
    vector_printer(post_result2);


    vector<int> in_result1 = inorderTraversal(root);
    vector_printer(in_result1);
    vector<int> in_result2 = inorderTraversal_test2(root);
    vector_printer(in_result2);


//    vector<vector<int>> result4 = levelOrderRecursive_test(root);
//    matrix_printer(result4);

}

