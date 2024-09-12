//
// Created by 朱俊驰 on 9/12/24.
//

#include "../helper.h"
#include "../treenode.h"

void path_tracker(TreeNode* node, vector<int>&path_sum , vector<int>&path_store){
    path_store.push_back(node->val);
    if(node->left==nullptr and node->right==nullptr){
        int temp_sum=0;
        for(int i : path_store){
            temp_sum+=i;
        }
        path_sum.push_back(temp_sum);
        return;
    }

    if(node->left){
        path_tracker(node->left,path_sum, path_store);
        path_store.pop_back();
    }
    if(node->right){
        path_tracker(node->right,path_sum, path_store);
        path_store.pop_back();
    }
}

bool hasPathSum_test1(TreeNode* root, int targetSum) {
    if(root== nullptr){
        return false;
    }
    vector<int>path_sum;
    vector<int>path_store;
    path_tracker(root, path_sum, path_store);
    for(int element:path_sum){
        if(element==targetSum){return true;}
    }
    return false;
}

bool path_tracker_test2(TreeNode* root, int targetSum){
    if(root->left== nullptr and root->right== nullptr and targetSum==0){return true;}
    if(root->left== nullptr and root->right== nullptr){return false;}
    if(root->left){
        targetSum-=root->left->val;
        if(path_tracker_test2(root->left, targetSum)){return true;}
        targetSum+=root->left->val;
    }
    if(root->right){
        targetSum-=root->right->val;
        if(path_tracker_test2(root->right, targetSum)){return true;}
        targetSum+=root->right->val;
    }
    return false;
}

bool hasPathSum_test2(TreeNode* root, int targetSum) {
    if(root== nullptr){
        return false;
    }

    return path_tracker_test2(root, targetSum-root->val);
}

void traversal(TreeNode* root, int targetSum, vector<vector<int>>&store, vector<int>&each_path){
    each_path.push_back(root->val);
    if(root->right==nullptr and root->left==nullptr and targetSum==0){store.push_back(each_path);}
    if(root->right==nullptr and root->left==nullptr){return ;}
    if(root->left){
        traversal(root->left, targetSum-root->left->val, store, each_path);
        each_path.pop_back();
    }
    if(root->right){
        traversal(root->right, targetSum-root->right->val, store, each_path);
        each_path.pop_back();
    }
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>>store;
    vector<int>each_path;
    if(root==nullptr){return store;}
    traversal(root, targetSum-root->val,store,each_path);
    return store;
}

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> my_queue;
    if(root){my_queue.push(root);}
    vector<int> store;
    int size_tracker=0;
    while(!my_queue.empty()){
        int size = my_queue.size();
        size_tracker = size;
        for(int i=0;i<size;++i){
            TreeNode* node = my_queue.front();
            my_queue.pop();
            store.push_back(node->val);
            if(node->left){my_queue.push(node->left);}
            if(node->right){my_queue.push(node->right);}
        }
    }
    return store.at(store.size()-size_tracker);
}

int getHeight(TreeNode* root) {
    if(root== nullptr){return 0;}
    int left = getHeight(root->left);
    if(left==-1){return -1;}
    int right = getHeight(root->right);
    if(right==-1){return -1;}
    if(abs(right-left)>1){
        return -1;
    } else{
        return max(right,left)+1;
    }
}

int maxDepth = INT_MIN;
void traversal(TreeNode* root, int depth, int &result){
    if(!root->right && !root->left){
        if(depth>maxDepth){
            maxDepth = depth;
            result=root->val;
        }
    }
    if(root->left){
        depth+=1;
        traversal(root->left, depth, result);
        depth-=1;
    }
    if(root->right){
        depth+=1;
        traversal(root->right, depth, result);
        depth-=1;
    }
}

int findBottomLeftValue_recursively(TreeNode* root) {
    int result;
    traversal(root,0, result);
    return result;
}

int main(){
    TreeNode* left_tree = new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr);
    TreeNode* right_tree = new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1)));
    TreeNode* root = new TreeNode(5, left_tree, right_tree);

    TreeNode* left_tree2 = new TreeNode(1, nullptr, nullptr);
    TreeNode* right_tree2 = new TreeNode(3, nullptr, nullptr);
    TreeNode* root2 = new TreeNode(2, left_tree2, right_tree2);
    cout<<findBottomLeftValue(root2)<<endl;
}