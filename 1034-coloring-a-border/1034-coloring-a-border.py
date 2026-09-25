from typing import List

class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:

        m, n = len(grid), len(grid[0])
        original = grid[row][col]

        visited = set()
        borders = []

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(r, c):
            visited.add((r,c))

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    borders.append((r, c))
                elif grid[nr][nc] != original:
                    borders.append((r, c))
                elif (nr,nc) not in visited:
                    dfs(nr, nc)
                
        dfs(row, col)

        for r, c in borders:
            grid[r][c] = color

        return grid