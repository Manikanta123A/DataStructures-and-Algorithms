class RangeFreqQuery:

    def __init__(self, arr: list[int]):
        self.arr = arr 
    @cache
    def query(self, left: int, right: int, value: int) -> int:
        new_arr = self.arr[left:right+1] 
        return new_arr.count(value)


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)