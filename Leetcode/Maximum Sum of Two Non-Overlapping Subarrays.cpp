//
//  Maximum Sum of Two Non-Overlapping Subarrays.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/13.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(N^2)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        for (int i = 1; i < n; i++)
            A[i] += A[i-1];
        int max_val = 0;
        int sum_n, sum_m;
        
        for (int i = L-1; i < n-M; i++){
            int max_m = 0;
            if (i == L-1) sum_n = A[i];
            else sum_n = A[i] - A[i-L];
            for (int j = i+M; j < n; j++)
                max_m = max(max_m, A[j] - A[j-M]);
            max_val = max(max_val, max_m + sum_n);
        }
        
        for (int i = M-1; i < n-L; i++){
            int max_n = 0;
            if (i == M-1) sum_m = A[i];
            else sum_m = A[i] - A[i-M];
            for (int j = i+L; j < n; j++)
                max_n = max(max_n, A[j] - A[j-L]);
            max_val = max(max_val, max_n + sum_m);
        }
        return max_val;
    }
};
