//
// Created by 朱俊驰 on 8/3/24.
//

#ifndef LEECODE_TREENODE_H
#define LEECODE_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename T>
vector<vector<T>> levelOrder(TreeNode* root){
    queue<TreeNode*> my_queue;
    if(root){
        my_queue.push(root);
    }
    vector<vector<T>>store;
    while(!my_queue.empty()){
        vector<T> each_line;
        int size = my_queue.size();
        for(int i=0;i<size;++i){
            TreeNode* node = my_queue.front();
            my_queue.pop();
            each_line.push_back(node->val);
            if(node->left){
                my_queue.push(node->left);
            }
            if(node->right){
                my_queue.push(node->right);
            }
        }
        store.push_back(each_line);
    }
    return store;
}

TreeNode* createTree(const std::vector<int>& nodes, int i) {
    if (i >= nodes.size() || nodes[i] == NULL) return NULL;
    TreeNode* root = new TreeNode(nodes[i]);
    root->left = createTree(nodes, 2 * i + 1);
    root->right = createTree(nodes, 2 * i + 2);
    return root;
}

#endif //LEECODE_TREENODE_H
