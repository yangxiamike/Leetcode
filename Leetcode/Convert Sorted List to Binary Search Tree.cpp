//
//  Convert Sorted List to Binary Search Tree.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/14.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//O(Nlog(n)) 可以继续改进
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return process(head);
    }
    TreeNode* process(ListNode* head){
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        
        ListNode* prev = nullptr;
        ListNode* middle = head;
        ListNode* end = head;
        while (end != nullptr && end->next != nullptr){
            prev = middle;
            middle = middle->next;
            end = end->next->next;
        }
        prev->next = nullptr;
        TreeNode* result = new TreeNode(middle->val);
        result->left = process(head);
        result->right = process(middle->next);
        return result;
    }
};
