//
// Created by 朱俊驰 on 9/12/24.
//

#include "../helper.h"
#include "../treenode.h"
//int result;
//void getDepth(TreeNode* root, int depth){
//    if(result>depth){
//        result = result;
//    } else{result=depth;}
//    if(root->left== nullptr and root->right == nullptr){
//        return;
//    }
//    if(root->left){
//        depth+=1;
//        getDepth(root->left, depth);
//        depth-=1;
//    }
//    if(root->right){
//        depth+=1;
//        getDepth(root->right, depth);
//        depth-=1;
//    }
//    return;
//}
int pre_order_maxDepth(TreeNode* root) {
    if(root == nullptr){return 0;}
    result=0;
    getDepth(root, 1);
    return result;

}
// zuo you zhong
vector<int> post_order(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> my_stack;
    if(root){my_stack.push(root);}
    while(!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();
        store.push_back(node->val);
        if(node->left!= nullptr){
            my_stack.push(node->left);
        }
        if(node->right!= nullptr){
            my_stack.push(node->right);
        }
    }
    reverse(store.begin(),store.end());
    return store;
}

int getHeight(TreeNode* root) {
    if(root== nullptr){return 0;}
    int left_height = getHeight(root->left);
    if(left_height==-1){return -1;}
    int right_height = getHeight(root->right);
    if(right_height==-1){return -1;}
    int result;
    if(abs(right_height-left_height)>1){
        result=-1;
    }else{
        result=max(right_height,left_height)+1;
    }
    return result;
}

bool isBalanced(TreeNode* root) {
    if( getHeight(root) == -1){
        return false;
    }
    return true;
}

void pre_traversal(TreeNode* root, vector<int>& store) {
    if(root== nullptr){
        return;
    }
    store.push_back(root->val);
    pre_traversal(root->left,store);
    pre_traversal(root->right,store);
}

vector<int> pre_order_traversal(TreeNode* root) {
    vector<int>store;
    if(root== nullptr){
        return store;
    }
    pre_traversal(root, store);
    return store;
}

void pre_path_tracker(TreeNode* node, vector<string>&store, vector<int>&path){
    path.push_back(node->val);
    if(node->left== nullptr and node->right== nullptr){
        string temp;
        for(int i=0;i<path.size()-1;++i){
            temp += to_string(path[i]);
            temp += "->";
        }
        temp+= to_string(path[path.size()-1]);
        store.push_back(temp);
        return;
    }

    if(node->left){
        pre_path_tracker(node->left, store, path);
        path.pop_back();
    }
    if(node->right){
        pre_path_tracker(node->right, store, path);
        path.pop_back();
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string>store;
    vector<int>path;
    if(root!= nullptr){
        pre_path_tracker(root, store, path);
    }
    return store;
}
//
//int sumOfLeftLeaves(TreeNode* root) {
//    if(root== nullptr){return 0;}
//    if(root->left== nullptr and root->right== nullptr){return 0;}
//    int left_sub_tree_value = sumOfLeftLeaves(root->left);
//    if(root->left!= nullptr and root->left->left== nullptr and root->left->right== nullptr){
//        left_sub_tree_value = root->left->val;
//    }
//    int right_sub_tree_value = sumOfLeftLeaves(root->right);
//    return right_sub_tree_value+left_sub_tree_value;
//}

int sumOfLeftLeaves(TreeNode* root) {
    if(root==nullptr){return 0;}
    if(root->left==nullptr and root->right==nullptr){return 0;}
    int left = sumOfLeftLeaves(root->left);
    if(root->left!=nullptr && root->left->left==nullptr and root->left->right== nullptr){
        left=root->left->val;
    }
    int right = sumOfLeftLeaves(root->right);
    return right+left;
}
//      1
//    2    3
//  4  5  6  7
//    8

int getNodesNum(TreeNode* cur) {
    if(cur== nullptr){return 0;}
    int left = getNodesNum(cur->left);
    int right = getNodesNum(cur->right);
    return left+right+1;
}

int getNodesNum_traversal(TreeNode* cur) {
    queue<TreeNode*> my_queue;
    if(cur){my_queue.push(cur);}
    int number=0;
    while (!my_queue.empty()){
        int size = my_queue.size();
        number+=size;
        for(int i=0;i<size;++i){
            TreeNode* node = my_queue.front();
            my_queue.pop();
            if(node->left){my_queue.push(node->left);}
            if(node->right){my_queue.push(node->right);}
        }
    }
    return number;
}

int main(){
    TreeNode* left_tree = new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(8), nullptr));
    TreeNode* right_tree = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    TreeNode* root = new TreeNode(1, left_tree, right_tree);
    cout<<sumOfLeftLeaves(root)<<endl;
//    cout<<getNodesNum_traversal(root);
    return 0;
}