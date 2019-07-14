//
//  Minimum Area Rectangle.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/13.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(N^2)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> S;
        for (auto& v:points) S.insert({v[0], v[1]});
        int min_area = 1e9;
        for (int i = 1; i < points.size(); i++){
            for (int j = 0; j < i; j++){
                if (points[i][0] != points[j][0] &&
                    points[i][1] != points[j][1] &&
                    S.count({points[i][0], points[j][1]}) &&
                    S.count({points[j][0], points[i][1]})){
                    int area = abs(points[i][0] - points[j][0])*
                    abs(points[i][1] - points[j][1]);
                    min_area = min(min_area, area);
                }
            }
        }
        return min_area == 1e9 ? 0 : min_area;
    };
};
