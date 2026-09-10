class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if len(edges) == 0:
            return [0]
        graph = [[] for _ in range(n)]
        indegree = [0]*n

        for a,b in edges: 
            graph[a].append(b)
            graph[b].append(a)
            indegree[a] +=1
            indegree[b] += 1

        queue = deque() 
        for i in range(n):
            if indegree[i] == 1:
                queue.append(i)
        remaining = n
        while remaining > 2:
            leave = len(queue)
            remaining -= leave
        
            for _ in range(leave):
                leaf = queue.popleft()

                for neighbor in graph[leaf]:
                    indegree[neighbor] -=1 
                    if indegree[neighbor] == 1:
                        queue.append(neighbor)

        return list(queue)