class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans = [] 
        def backtrack(s,open_p, close_p):
            if len(s) == 2*n:
                ans.append(s) 
                return
            if open_p < n and open_p >= close_p: 
                backtrack(s + '(', open_p + 1, close_p)
            if close_p < n and open_p >= close_p:
                backtrack(s + ')', open_p , close_p+1)
        
        backtrack("",0,0)
        return ans
