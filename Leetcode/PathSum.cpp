//
//  PathSum.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/14.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//Depth First Search
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        vector<int> path;
        PathSum(root, sum, result, path);
        return result;
    }
    void PathSum(TreeNode* node, int remain,
                 vector<vector<int>>& pathsum, vector<int>& path){
        path.push_back(node -> val);
        if (node -> left == nullptr && node -> right == nullptr
            && remain == node-> val){
            pathsum.push_back(path);
        }
        else{
            if (node -> left != nullptr){
                PathSum(node -> left, remain - node -> val, pathsum, path);
            }
            if (node -> right != nullptr){
                PathSum(node -> right, remain - node -> val, pathsum, path);
            }
        }
        path.pop_back();
    }
};
