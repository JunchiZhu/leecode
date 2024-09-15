//
// Created by 朱俊驰 on 9/14/24.
//

#include "../helper.h"
#include "../treenode.h"

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    auto iter = max_element(nums.begin(),nums.end());
    int root_index = distance(nums.begin(),iter);
    auto* root = new TreeNode(nums[root_index]);

    if(root_index>0){
        vector<int> left = vector<int>(nums.begin(), nums.begin()+root_index);
        root->left = constructMaximumBinaryTree(left);
    }
    if(root_index<nums.size()-1){
        vector<int> right = vector<int>(nums.begin()+root_index+1, nums.end());
        root->right = constructMaximumBinaryTree(right);
    }
    return root;
}


TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 and !root2){
        return root1;
    }
    if(!root1 and root2){
        return root2;
    }
    queue<TreeNode*> my_queue;
    if(root1 and root2){
        my_queue.push(root1);
        my_queue.push(root2);
    }
    while(!my_queue.empty()){
        TreeNode* node1 = my_queue.front();
        my_queue.pop();
        TreeNode* node2 = my_queue.front();
        my_queue.pop();
        node1->val += node2->val;

        if(node1->left != nullptr and node2->left != nullptr){
            my_queue.push(node1->left);
            my_queue.push(node2->left);
        }
        if(node1->right != nullptr and node2->right != nullptr){
            my_queue.push(node1->right);
            my_queue.push(node2->right);
        }
        if(node1->left == nullptr and node2->left != nullptr){
            node1->left = node2->left;
        }
        if(node1->right == nullptr and node2->right != nullptr){
            node1->right = node2->right;
        }
        if(node1->left != nullptr and node2->left == nullptr){
            node1->left = node1->left;
        }
        if(node1->right != nullptr and node2->right == nullptr){
            node1->right = node1->right;
        }
    }
    return root1;
}

TreeNode* mergeTrees_recursively(TreeNode* root1, TreeNode* root2) {
    if(root1 and !root2){
        return root1;
    }
    if(!root1 and root2){
        return root2;
    }
    if(root1== nullptr and root2 == nullptr){
        return root1;
    }
    root1->val += root2->val;
    root1->left = mergeTrees_recursively(root1->left, root2->left);
    root1->right = mergeTrees_recursively(root1->right, root2->right);
    return root1;
}

bool isSymmetric(TreeNode* root) {
    if(root== nullptr){return true;}
    queue<TreeNode*> my_queue;

    my_queue.push(root->left);
    my_queue.push(root->right);

    while(!my_queue.empty()){
        TreeNode* node1 = my_queue.front();
        my_queue.pop();
        TreeNode* node2 = my_queue.front();
        my_queue.pop();
        if(node1== nullptr and node2== nullptr){
            continue;
        }
        if((node1== nullptr and node2!= nullptr) or (node1 != nullptr and node2== nullptr) or node1->val != node2->val ){
            return false;
        }
        my_queue.push(node1->left);
        my_queue.push(node2->right);
        my_queue.push(node1->right);
        my_queue.push(node2->left);
    }
    return true;
}

bool compare_recursively(TreeNode* left, TreeNode* right){
    if(left == nullptr and right!= nullptr){return false;}
    if(left != nullptr and right== nullptr){return false;}
    if(left == nullptr and right== nullptr){return true;}
    if(left->val != right->val){return false;}
    bool left_node = compare_recursively(left->left, right->right );
    bool right_node = compare_recursively(left->right, right->left);
    bool isSame = left_node && right_node;
    return isSame;
}
bool isSymmetric_recursively(TreeNode* root) {
    if(root== nullptr){return true;}
    return compare_recursively(root->left, root->right);
}

TreeNode* searchBST(TreeNode* root, int val) {
    if(root== nullptr or root->val==val){return root;}
    if(root->val>val){
        return searchBST(root->left, val);
    }
    if(root->val<val){
        return searchBST(root->right, val);
    }
    return nullptr;
}

TreeNode* searchBST_2(TreeNode* root, int val) {
    if(root== nullptr){
        return nullptr;
    }
    while(root!= nullptr){
        if(root->val>val){
            root=root->left;
        }
        else if(root->val<val){
            root=root->right;
        }
        else{
            return root;
        }
    }
    return nullptr;
}


bool isValidBST(TreeNode* root) {
    if(root== nullptr){return true;}
    vector<int> store;
    stack<TreeNode*> my_stack;
    TreeNode* cur = root;
    while(cur != nullptr|| !my_stack.empty()){
        if(cur!= nullptr){
            my_stack.push(cur);
            cur=cur->left;
        } else{
            cur=my_stack.top();
            my_stack.pop();
            store.push_back(cur->val);
            cur=cur->right;
        }
    }

    for (int i = 1; i < store.size(); i++) {
        if (store[i] <= store[i - 1]) return false;
    }
    return true;
}
int main(){
    // Construct root1 = [1, 3, 2, 5]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    // Construct root2 = [2, 1, 3, null, 4, null, 7]
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    TreeNode* merged = mergeTrees_recursively(root1, root2);
    matrix_printer(levelOrder<int>(merged));


    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    cout<<isValidBST(root)<<endl;
    return 0;
}