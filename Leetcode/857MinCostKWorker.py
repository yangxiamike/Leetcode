"""

Heap堆做法 (O(NlogN))

按照薪水/能力比值进行排序，这样可以保证迭代时，当前选择的K个员工均满足最低的薪水/能力比值
用能力加和乘以当前员工的薪水/能力比值，可以得到当前的薪水总额

如果超过了K个，将堆中能力值最高的员工推出，这样可以保证薪水付的更少

"""





class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        ratios = [(w / q, w, q for w, q in zip(wage, quality))]

        sumq = 0
        ans = float('inf')
        heap = []
        ratios.sort()

        for r, w, q in ratios:
            sumq += q
            heapq.heappush(heap, -q)

            if len(heap) > K:
                sumq += heapq.heappop(heap)

            if len(heap) == K:
                ans = min(ans, sumq * r)
        
        return q
