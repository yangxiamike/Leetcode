"""
Heap + Counter 做法 (O(NlogN))

用Counter 计数

用Heap得到K个最常见的word，设定自定义的比大小方式

最后得到K个字的列表

"""



class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:

        from collections import Counter
        counter = Counter(words)

        heap = []

        for word, count in counter.items():
            heapq.heappush(heap, WordCount(word, count))

            if len(heap) > k:
                heapq.heappop(heap)

        ans = []
        while heap:
            word = heapq.heappop(heap).word
            ans.append(word)

        return ans[::-1]
        

class WordCount:
    def __init__(self, word, count):
        self.word = word
        self.count = count
    
    def __lt__(self, other):

        if self.count == other.count:
            return self.word > other.word
        return self.count < other.count

    def __gt__(self, other):

        if self.count == other.count:
            return self.word < other.word
        return self.count > other.count