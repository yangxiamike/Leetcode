//
//  Minimum Increment to Make Array Unique.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/13.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(N)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() == 0) return 0;
        vector<int> dict_num(41000, 0);
        queue<int> que;
        int result = 0;
        for (int num:A) dict_num[num]++;
        for (int i = 0; i < 41000; i++){
            if (dict_num[i] > 0) {
                while (dict_num[i]-- > 1)
                    que.push(i);
                continue;
            }
            if (!que.empty() && dict_num[i] == 0){
                result += i - que.front();
                que.pop();
            }
        }
        return result;
    }
};
