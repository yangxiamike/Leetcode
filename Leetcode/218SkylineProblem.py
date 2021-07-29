

"""

利用Priority Queue管理max value值

将points 按照 start 和 end 分开，成为（x position, height, up/down)
将分隔开的点，按照x position 进行排序（O(nlogn)），有三个edge case
1. up情况下，相同x值，height按照从大到小进行排列
2. down情况下，相同x值，height按照从小到达进行排列
3. 前个是down，后个是up，相同x值，height按照up，down的顺序

对points进行迭代，
1. 如果是up，将height加入priority queue，
    如果max value改变，记录这个点
2. 如果是down，
    如果max value和当前值相同，从queue删除最大值，同时从delete dict中查看queue top是不是需要之前删除的点，如果max value改变，记录这个点
    否则，记录下需要删除的点
"""

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        result = []
        
        delete = {}
        heap = []
        max_value = 0
        heapq.heappush(heap, max_value)

        points_x = [(point[0], -point[2]) for point in buildings]
        points_y = [(point[1], point[2]) for point in buildings]

        points = points_x + points_y
        points.sort(key = lambda x: (x[0], x[1]))

        for point in points:
            if point[1] < 0:
                heapq.heappush(heap, point[1])
                if -point[1] > max_value:
                    max_value = -point[1]
                    result.append([point[0], max_value])
            else:
                curr = -point[1]
                if curr == max_value:
                    heapq.heappop(heap)
                    while heapq[0] in delete:
                        val_del = heapq[0]
                        heapq.heappop(heap)
                        delete[val_del] -= 1
                        if delete[val_del] == 0:
                            del delete[val_del]
                    if -heap[0] < max_value:
                        result.append([point[0], max_value])
                else:
                    if curr not in delete:
                        delete[curr] = 1
                    else:
                        delete[curr] += 1
        return result


        
