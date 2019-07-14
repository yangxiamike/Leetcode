//
//  Construct Binary Tree from Inorder and Postorder Traversal.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/14.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>

//O(N)
class Solution {
private:
    int n = 0;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0)
            return NULL;
        n = postorder.size() - 1;
        return buildTree(inorder, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                        int left, int right){
        if (left > right)
            return NULL;
        int middle = postorder[n--];
        if (left == right){
            TreeNode* root1 = new TreeNode(inorder[left]);
            return root1;
        }
        TreeNode* root = new TreeNode(middle);
        int index;
        for (int i = right; i >= left; i--){
            if (inorder[i] == middle) {
                index = i;
                break;
            }
        }
        TreeNode* right1=buildTree(inorder,postorder,index+1,right);
        TreeNode* left1=buildTree(inorder,postorder,left,index-1);
        root->right = right1;
        root->left = left1;
        return root;
    }
};
