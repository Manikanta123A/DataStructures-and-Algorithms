class Solution:
    def countPoints(self, rings: str) -> int:
        rods = [ set() for _ in range(10)]

        for i in range(0,len(rings),2):
            color = rings[i]
            rods[int(rings[i+1])].add(color) 

        return sum ( len(colors) ==3 for colors in rods )