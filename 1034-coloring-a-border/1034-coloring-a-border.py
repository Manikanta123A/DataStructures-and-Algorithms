from typing import List

class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:

        m, n = len(grid), len(grid[0])
        original = grid[row][col]

        visited = [[False] * n for _ in range(m)]
        borders = []

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(r, c):
            visited[r][c] = True

            is_border = False

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    is_border = True
                elif grid[nr][nc] != original:
                    is_border = True
                elif not visited[nr][nc]:
                    dfs(nr, nc)

            if is_border:
                borders.append((r, c))

        dfs(row, col)

        for r, c in borders:
            grid[r][c] = color

        return grid